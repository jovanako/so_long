/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map_checks1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:42:23 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/21 16:45:29 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	perror_and_return(char *error_message, int n)
{
	perror(error_message);
	return (n);
}

int	check_walls(t_map *map)
{
	int		i;
	int		j;
	char	*error;

	error = "Error\nThe map is not enclosed by walls.";
	i = 0;
	j = 0;
	while (j < map->columns)
	{
		if ((map->grid[i][j] != '1')
			|| (map->grid[i + (map->rows - 1)][j] != '1'))
			return (perror_and_return(error, 0));
		j++;
	}
	i++;
	j = 0;
	while (i < (map->rows - 1))
	{
		if ((map->grid[i][j] != '1')
			|| (map->grid[i][j + (map->columns - 1)] != '1'))
			return (perror_and_return(error, 0));
		i++;
	}
	return (1);
}

int     is_rectangular(t_map *map)
{
    int     i;
    int     len;
    int     current_len;
	char	*error;

	error = "Error\nThe map is not rectangular.";
    len = ft_strlen(map->grid[0]) - 1;
    i = 1;
    while (i < map->rows)
    {
        current_len = ft_strlen(map->grid[i]);
        if (map->grid[i][current_len - 1] == '\n')
            current_len--;
        if (current_len != len)
            return (perror_and_return(error, 0));
        i++;
    }
    return (1);
}

static int	is_in(char c)
{
	int		i;
	char	*set;

	i = 0;
	set = "01CEP";
	while (i < 5)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	valid_characters(t_map *map)
{
	int		i;
	int		j;
	char	*error;

	error = "Error\nThe map contains invalid characters.";
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (!(is_in(map->grid[i][j])))
				return (perror_and_return(error, 0));
			j++;
		}
		i++;
	}
	return (1);
}
