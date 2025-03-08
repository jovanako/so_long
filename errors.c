/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:07:04 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/07 17:07:07 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int  print_error_and_return(char *error_message, int n)
{
    perror(error_message);
    return (n);
}

int    check_walls(t_map map)
{
    int         i;
    int         j;

    i = 0;
    j = 0;
    while (j < map.width)
    {
        if ((map.matrix[i][j] != '1') || (map.matrix[i + (map.height - 1)][j] != '1'))
            print_error_and_return("Error\nThe map is not enclosed by walls.", 0);
        j++;
    }
    i++;
    j = 0;
    while (i < (map.height - 1))
    {
        if ((map.matrix[i][j] != '1') || (map.matrix[i][j + (map.width - 1)] != '1'))
            print_error_and_return("Error\nThe map is not enclosed by walls.", 0);
        i++;
    }
    return (1);
}

static int     check_duplicates(t_map map, char c)
{
    int     i;
    int     count;

    count = 0;
    i = 0;
    while (i < map.height)
    {
            if (ft_strchr(map.matrix[i], c))
                count++;
        i++;
    }
    return (count);
}

int     dup_or_no_player(t_map map)
{
    if (check_duplicates(map, 'P') > 1)
        print_error_and_return("Error\nThe map contains more than one player.", 1);
    else if (check_duplicates(map, 'P') == 0)
        print_error_and_return("Error\nThe map has no players.", 1);
    return (0);
}

int     dup_or_no_exit(t_map map)
{
    if (check_duplicates(map, 'E') > 1)
        print_error_and_return("Error\nThe map contains more than one exit.", 1);
    else if (check_duplicates(map, 'E') == 0)
        print_error_and_return("Error\nThe map has no exit.", 1);
    return (0);
}

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
            print_error_and_return("Error\nThe map is not rectangular.", 0);
        i++;
    }
    return (1);
}