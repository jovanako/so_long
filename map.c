/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:15:28 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/21 16:55:31 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_size(char *map_name, t_map *map)
{
	int		fd;
	char	*line;

	if (!valid_mapname_extension(map_name))
		return (perror_and_return("Error\nIncorrect map file extension.",
				1));
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (perror_and_return("Error\nBad file descriptor.", 1));
	line = get_next_line(fd);
	if (!line)
		return (perror_and_return("Error\nEmpty map file.", 1));
	map->columns = ft_strlen(line) - 1;
	map->rows = 0;
	while (line)
	{
		free(line);
		map->rows++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

static void	parse_line(t_map *map, char *line, int row_number)
{
	int		i;
	int		line_len;

	i = 0;
	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line_len--;
	while (i < line_len)
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

static int	load_grid(char *map_name, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	map->grid = malloc(map->rows * sizeof(char *));
	if (!map->grid)
		return (0);
	map->n_collectibles = 0;
	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map->grid[i] = line;
		parse_line(map, line, i);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}

int	load_map(int n, char *map_name, t_map *map)
{
	if (n != 2)
		return (1);
	if (map_size(map_name, map) == 1)
		return (1);
	if (!load_grid(map_name, map))
		return (1);
	if (!is_rectangular(map) || !check_walls(map) || !valid_characters(map)
		|| dup_or_no_player(map) || dup_or_no_exit(map))
		return (free_map_and_return(map));
	if (!is_valid_path(map))
	{
		free_map_with_grid(map);
		perror("Error\nNo valid path.");
		return (1);
	}
	if (map->n_collectibles == 0)
	{
		free_map_with_grid(map);
		perror("Error\nThe map has no collectibles.");
		return (1);
	}
	return (0);
}

void	free_map_with_grid(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->rows)
		free(map->grid[i++]);
	free(map->grid);
}
