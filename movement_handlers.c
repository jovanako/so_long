/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:00:47 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/12 09:25:44 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		move_right(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map.h)
	{
		j = 0;
		while (j < data->map.w)
		{
			if (data->map.matrix[i][j] == 'P' && data->map.matrix[i][j + 1] != '1' && data->map.matrix[i][j + 1] != 'E')
			{
				data->map.matrix[i][j] = '0';
				data->map.matrix[i][j + 1] = 'P';
				break ;
			}
			else if (data->map.matrix[i][j] == 'P' && data->map.matrix[i][j + 1] == 'E')
				end_program(data->mlx);
			j++;
		}
		i++;
	}
	fill_window_with_tiles(&(data->map), &(data->mlx), &(data->img));
}

void		move_left(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map.h)
	{
		j = 0;
		while (j < data->map.w)
		{
			if (data->map.matrix[i][j] == 'P' && data->map.matrix[i][j - 1] != '1' && data->map.matrix[i][j - 1] != 'E')
			{
				data->map.matrix[i][j] = '0';
				data->map.matrix[i][j - 1] = 'P';
				break ;
			}
			else if (data->map.matrix[i][j] == 'P' && data->map.matrix[i][j - 1] == 'E')
				end_program(data->mlx);
			j++;
		}
		i++;
	}
	fill_window_with_tiles(&(data->map), &(data->mlx), &(data->img));
}

void		move_up(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map.h)
	{
		j = 0;
		while (j < data->map.w)
		{
			if (data->map.matrix[i][j] == 'P' && data->map.matrix[i - 1][j] != '1' && data->map.matrix[i - 1][j] != 'E')
			{
				data->map.matrix[i][j] = '0';
				data->map.matrix[i - 1][j] = 'P';
				break ;
			}
			else if (data->map.matrix[i][j] == 'P' && data->map.matrix[i - 1][j] == 'E')
				end_program(data->mlx);
			j++;
		}
		i++;
	}
	fill_window_with_tiles(&(data->map), &(data->mlx), &(data->img));
}

void		move_down(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map.h)
	{
		j = 0;
		while (j < data->map.w)
		{
			if (data->map.matrix[i][j] == 'P' && data->map.matrix[i + 1][j] != '1' && data->map.matrix[i + 1][j] != 'E')
			{
				data->map.matrix[i][j] = '0';
				data->map.matrix[i + 1][j] = 'P';
				break ;
			}
			else if (data->map.matrix[i][j] == 'P' && data->map.matrix[i + 1][j] == 'E')
				end_program(data->mlx);
			j++;
		}
		i++;
	}
	fill_window_with_tiles(&(data->map), &(data->mlx), &(data->img));
}