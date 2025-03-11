/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:13:01 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/11 20:13:02 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int		count_c(char *s, char c, int len)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < len)
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

static int     check_duplicates(t_map map, char c)
{
    int     i;
    int     count;

    count = 0;
    i = 0;
    while (i < map.h)
    {
        count += count_c(map.matrix[i], c, map.w);
        i++;
    }
    return (count);
}

int     dup_or_no_player(t_map map)
{
    char    *error1;
    char    *error2;

    error1 = "Error\nThe map contains more than one player.";
    error2 = "Error\nThe map has no players.";
    if (check_duplicates(map, 'P') > 1)
        return (print_error_and_return(error1, 1));
    else if (check_duplicates(map, 'P') == 0)
        return (print_error_and_return(error2, 1));
    return (0);
}

int     dup_or_no_exit(t_map map)
{
    char    *error1;
    char    *error2;

    error1 = "Error\nThe map contains more than one exit.";
    error2 = "Error\nThe map has no exit.";
    if (check_duplicates(map, 'E') > 1)
        return (print_error_and_return(error1, 1));
    else if (check_duplicates(map, 'E') == 0)
        return (print_error_and_return(error2, 1));
    return (0);
}

int     collectible(t_map map)
{
    int     i;
    int     j;
    char    *error;
    
    error = "Error\nThe map has no collectibles.";
    i = 0;
    while (i < map.h)
    {
        j = 0;
        while (j < map.w)
        {
            if (map.matrix[i][j] == 'C')
                return (1);
            j++;
        }
        i++;
    }
    return (print_error_and_return(error, 0));
}