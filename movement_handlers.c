/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:00:47 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/12 11:23:08 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_window_with_tiles(t_map *map, t_mlx *mlx, t_img *img)
{
	int		i;
	int		j;
    
    i = 0;
	mlx->h = TILE_HEIGHT * map->h;
	while ((i * TILE_HEIGHT) < mlx->h)
	{
		j = 0;
		while (j < map->w)
		{
            get_image(map->matrix[i][j], img, &(map->tiles));
            mlx_put_image_to_window(mlx->con, mlx->win, img->img, j * TILE_WIDTH, i * TILE_HEIGHT);
            j++;
		}
		i++;
	}
}

void		move_right(t_data *data)
{
	int		i;
	int		j;
	int		player_found;

	i = 0;
	player_found = 0;
	while (i < data->map.h && !player_found)
	{
		j = 0;
		while (j < data->map.w && !player_found)
		{
			if (data->map.matrix[i][j] == 'P' && data->map.matrix[i][j + 1] != '1' && data->map.matrix[i][j + 1] != 'E')
			{
				data->map.matrix[i][j] = '0';
				data->map.matrix[i][j + 1] = 'P';
				player_found = 1;
			}
			else if (data->map.matrix[i][j] == 'P' && data->map.matrix[i][j + 1] == 'E')
				close_window(&(data->mlx), 0);
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
	int		player_found;

	i = 0;
	player_found = 0;
	while (i < data->map.h && !player_found)
	{
		j = 0;
		while (j < data->map.w && !player_found)
		{
			if (data->map.matrix[i][j] == 'P' && data->map.matrix[i][j - 1] != '1' && data->map.matrix[i][j - 1] != 'E')
			{
				data->map.matrix[i][j] = '0';
				data->map.matrix[i][j - 1] = 'P';
				player_found = 1;
			}
			else if (data->map.matrix[i][j] == 'P' && data->map.matrix[i][j - 1] == 'E')
				close_window(&(data->mlx), 0);
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
	int		player_found;

	i = 0;
	player_found = 0;
	while (i < data->map.h && !player_found)
	{
		j = 0;
		while (j < data->map.w && !player_found)
		{
			if (data->map.matrix[i][j] == 'P' && data->map.matrix[i - 1][j] != '1' && data->map.matrix[i - 1][j] != 'E')
			{
				data->map.matrix[i][j] = '0';
				data->map.matrix[i - 1][j] = 'P';
				player_found = 1;
			}
			else if (data->map.matrix[i][j] == 'P' && data->map.matrix[i - 1][j] == 'E')
				close_window(&(data->mlx), 0);
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
	int		player_found;

	i = 0;
	player_found = 0;
	while (i < data->map.h && !player_found)
	{
		j = 0;
		while (j < data->map.w && !player_found)
		{
			if (data->map.matrix[i][j] == 'P' && data->map.matrix[i + 1][j] != '1' && data->map.matrix[i + 1][j] != 'E')
			{
				data->map.matrix[i][j] = '0';
				data->map.matrix[i + 1][j] = 'P';
				player_found = 1;
			}
			else if (data->map.matrix[i][j] == 'P' && data->map.matrix[i + 1][j] == 'E')
				close_window(&(data->mlx), 0);
			j++;
		}
		i++;
	}
	fill_window_with_tiles(&(data->map), &(data->mlx), &(data->img));
}