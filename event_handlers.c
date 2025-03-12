/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:14:41 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/12 09:34:17 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_program(t_mlx mlx)
{
	mlx_destroy_window(mlx.con, mlx.win);
    free(mlx.con);
}

int		key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		end_program(data->mlx);
		exit(0);
		return (0);
	}
	else if (keycode == 65363 || keycode == 100)
	{
		move_right(data);
		
	}
	else if (keycode == 65361 || keycode == 97)
		move_left(data);
	else if (keycode == 65362 || keycode == 119)
		move_up(data);
	else if (keycode == 65364 || keycode == 115)
		move_down(data);
	return (0);
}

int		close_window(t_mlx *mlx)
{
	end_program(*mlx);
	exit(0);
	return (0);
}



