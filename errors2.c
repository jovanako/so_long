/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:07:04 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/07 17:07:07 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     is_rectangular(t_map map)
{
    int     i;
    int     len;
    int     current_len;

    len = ft_strlen(map.matrix[0]) - 1;
    i = 1;
    while (i < map.height)
    {
        current_len = ft_strlen(map.matrix[i]);
        if (map.matrix[i][current_len - 1] == '\n')
            current_len--;
        if (current_len != len)
            return (print_error_and_return("Error\nThe map is not rectangular.", 0));
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

int		has_only_valid_characters(t_map map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (!(is_in(map.matrix[i][j])))
				return (print_error_and_return("Error\nThe map contains invalid characters.", 0));
			j++;
		}
		i++;
	}
	return (1);
}