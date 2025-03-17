/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:15:28 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/17 17:23:54 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_size(char *map_name, t_map *map)
{
    int     fd;
    char    *line;
	
	if (!valid_mapname_extension(map_name))
		return (print_error_and_return("Error\nIncorrect map file extension.", 1));
    fd = open(map_name, O_RDONLY);
    line = get_next_line(fd);
	if (!line || fd == -1)
		return (print_error_and_return("Error\nEmpty map file / Bad file descriptor.", 1));
    map->columns = ft_strlen(line) - 1;
	free(line);
    map->rows = 1;
    while (line)
    {
        line = get_next_line(fd);
        if (line)
            map->rows++;
		free(line);
    }
    map->grid = malloc(map->rows * sizeof(char *));
	if (!map->grid)
		return (1);
    close(fd);
	return (0);
}
static void	parse_line(t_map *map, char *line, int row_number)
{
	int		i;

	i = 0;
	while (i < map->columns)
	{
		if (line[i] == 'C')
			map->n_collectibles++;
		else if (line[i] == 'P')
		{
			map->x_player = i;
			map->y_player = row_number;
		}
		i++;
	}
}

static void	load_grid(char *map_name, t_map *map)
{
    int     fd;
    int     i;
    char    *line;
	
	map->n_collectibles = 0;
    fd = open(map_name, O_RDONLY);
    line = get_next_line(fd);
    i = 0;
    while(line)
    {
        map->grid[i] = line;
		parse_line(map, line, i);
        line = get_next_line(fd);
        i++;
    }
    close(fd);
}

int	load_map(char *map_name, t_map *map)
{
	if (map_size(map_name, map) == 1)
		return (1);
	load_grid(map_name, map);
	if (!is_rectangular(*map) || !check_walls(*map) || !valid_characters(*map)
		|| dup_or_no_player(*map) || dup_or_no_exit(*map))
		return (1);
	if (!is_valid_path(map))
		return (print_error_and_return("Error\nNo valid path.", 1));
	if (map->n_collectibles == 0)
		return (print_error_and_return("Error\nThe map has no collectibles.", 1));
	return (0);
}

void	free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->rows)
		free(map->grid[i++]);
	free(map->grid);
}