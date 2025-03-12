/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:09:18 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/12 11:15:36 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     main(int argc, char *argv[])
{
    t_mlx   mlx = { .title = "Collect the mushrooms, Miraculix!" };
    t_img   img = { .w = TILE_WIDTH, .h = TILE_HEIGHT };
    t_map   map;
    t_data  data;
    
	if (argc)
		map_size(argv[1], &map);
    if (!map.matrix)
        return (1);
    if (!create_matrix(&map, argv[1]))
        return (1);
    mlx.con = mlx_init();
    if (!mlx.con)
		free_map_and_close(map);
	mlx.win = mlx_new_window(mlx.con, TILE_WIDTH * map.w, TILE_HEIGHT * map.h, mlx.title);
    if (!mlx.win)
        close_window(&mlx, 1);
    load_tiles(&map, &mlx, &img);
    fill_window_with_tiles(&map, &mlx, &img);
    data.mlx = mlx;
    data.map = map;
    data.img = img;
    mlx_key_hook(mlx.win, key_press, &data);
    mlx_hook(mlx.win, 17, 1L<<17, close_window, &mlx);
    mlx_loop(mlx.con);
    return (0);
}

