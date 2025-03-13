/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:15:28 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/13 12:10:01 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_size(char *map_name, t_map *map)
{
    int     fd;
    char    *line;
    int     height;

    fd = open(map_name, O_RDONLY);
    line = get_next_line(fd);
    map->columns = ft_strlen(line) - 1;
    height = 1;
    while (line)
    {
        line = get_next_line(fd);
        if (line)
            height++;
    }
    map->rows = height;
    map->grid = malloc(map->rows * sizeof(char *));
	if (!map->grid)
		return (1);
    close(fd);
    free(line);
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
	if (!check_walls(*map) || !is_rectangular(*map) || !valid_characters(*map)
		|| dup_or_no_player(*map) || dup_or_no_exit(*map))
		return (1);
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