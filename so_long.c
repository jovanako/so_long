/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:38:20 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/13 13:32:04 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     main(int argc, char *argv[])
{
	t_mlx	mlx = { .title = "Collect the mushrooms, Miraculix!" };
	t_map	map;
    t_data  data;

	if (argc != 2 || (load_map(argv[1], &map) == 1))
		return (1);
	data.map = &map;
	mlx.con = mlx_init();
    if (!mlx.con)
		end_program_and_return(&data);
	data.mlx = &mlx;
	mlx.win = mlx_new_window(mlx.con, TILE_WIDTH * map.columns, 
		TILE_HEIGHT * map.rows, mlx.title);
	if (!mlx.win)
		end_program_and_return(&data);
	load_tiles(&data);
	fill_window_with_tiles(&mlx, &map, &(data.tiles));
	mlx_key_hook(mlx.win, key_press, &data);
	mlx_hook(mlx.win, 17, 1L<<17, end_program_and_return, &mlx);
	mlx_loop(mlx.con);
	return (0);	
}

