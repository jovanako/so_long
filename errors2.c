/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:10:11 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/11 20:12:31 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int  print_error_and_return(char *error_message, int n)
{
    perror(error_message);
    return (n);
}

int    check_walls(t_map map)
{
    int     i;
    int     j;
    char    *error;        

    error = "Error\nThe map is not enclosed by walls.";
    i = 0;
    j = 0;
    while (j < map.w)
    {
        if ((map.matrix[i][j] != '1') || (map.matrix[i + (map.h - 1)][j] != '1'))
            return (print_error_and_return(error, 0));
        j++;
    }
    i++;
    j = 0;
    while (i < (map.h - 1))
    {
        if ((map.matrix[i][j] != '1') || (map.matrix[i][j + (map.w - 1)] != '1'))
            return (print_error_and_return(error, 0));
        i++;
    }
    return (1);
}

int     is_rectangular(t_map map)
{
    int     i;
    int     len;
    int     current_len;
	char	*error;

	error = "Error\nThe map is not rectangular.";
    len = ft_strlen(map.matrix[0]) - 1;
    i = 1;
    while (i < map.h)
    {
        current_len = ft_strlen(map.matrix[i]);
        if (map.matrix[i][current_len - 1] == '\n')
            current_len--;
        if (current_len != len)
            return (print_error_and_return(error, 0));
        i++;
    }
    return (1);
}

int		is_in(char c)
{
	char	*set;

	set = "01CEP\0";
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int		valid_characters(t_map map)
{
	int		i;
	int		j;
	char	*error;

	error = "Error\nThe map contains invalid characters.";
	i = 0;
	while (i < map.h)
	{
		j = 0;
		while (j < map.w)
		{
			if (!(is_in(map.matrix[i][j])))
				return (print_error_and_return(error, 0));
			j++;
		}
		i++;
	}
	return (1);
}