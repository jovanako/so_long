/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:14:41 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/11 22:33:03 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_program(t_mlx mlx, t_img img)
{
	mlx_destroy_display(mlx.con);
    mlx_destroy_image(mlx.con, img.img);
    free(mlx.con);
}

int		key_press(int keycode, t_data *data)
{
	printf("Key pressed: %d, map[1][1]: %c\n", keycode, data->map.matrix[1][1]);
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx.con, data->mlx.win);
		end_program(data->mlx, data->img);
		exit(0);
		return (0);
	}
	else if (keycode == 65363)
		move_right(data);
	return (0);
}

int		button_release(t_mlx *mlx)
{
	mlx_destroy_window(mlx->con, mlx->win);
	return (0);
}

// int		move_right(t_data *data)
// {
// 	int     i;
//     int     j;

//     i = 0;
//     while (i < data->map.h)
//     {
//         j = 0;
//         while (j < data->map.w)
//         {
//             if (data->map.matrix[i][j] == 'P')
//             {
//                 data->map.x_player = i * TILE_WIDTH;
//                 data->map.y_player = j * TILE_HEIGHT;
//                 break ;
//             }
//         }
//     }
// 	if (data->map.matrix[i][j + 1] != '1')
// 	{
// 		get_image('0', &(data->img), &(data->map.tiles));
// 		mlx_put_image_to_window(data->mlx.con, data->mlx.win,
// 			data->img.img, data->map.x_player, data->map.y_player);
// 		get_image('P', &(data->img), &(data->map.tiles));
// 		data->map.x = data->map.x_player + TILE_WIDTH;
// 		mlx_put_image_to_window(data->mlx.con, data->mlx.win,
// 			data->img.img, data->map.x, data->map.y_player);		
// 	}
// 	return (0);	
// }

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
			if (data->map.matrix[i][j] == 'P' && data->map.matrix[i][j + 1] != '1')
			{
				data->map.matrix[i][j] = '0';
				data->map.matrix[i][j + 1] = 'P';
				break ;
			}
			j++;
		}
		i++;
	}
	mlx_clear_window(&(data->mlx.con), &(data->mlx.win));
	fill_window_with_tiles(&(data->map), &(data->mlx), &(data->img));
}



