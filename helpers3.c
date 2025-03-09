/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:52:38 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/04 13:52:51 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		key_press(int keycode, t_mlx *mlx)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 65307)
		mlx_destroy_window(mlx->con, mlx->win);
	if (keycode == 65363)
	{

	}
	return (0);
}

int		button_release(t_mlx *mlx)
{
	mlx_destroy_window(mlx->con, mlx->win);
	return (0);
}