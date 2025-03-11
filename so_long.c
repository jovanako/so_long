/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:09:18 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/11 22:33:32 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_window_with_tiles(t_map *map, t_mlx *mlx, t_img *img)
{
	int		i;
	int		j;
    
	map->x = 0;
	i = 0;
	while (map->y < mlx->h)
	{
		map->x = 0;
		j = 0;
		while (j < map->w)
		{
            get_image(map->matrix[i][j], img, &(map->tiles));
            mlx_put_image_to_window(mlx->con, mlx->win, img->img, map->x, map->y);
            map->x += img->w;
            j++;
		}
		map->y += img->h;
		i++;
	}
}

int     main(int argc, char *argv[])
{
    t_mlx   mlx = { .title = "Collect the mushrooms, Miraculix!" };
    t_img   img = { .w = TILE_WIDTH, .h = TILE_HEIGHT };
    t_map   map = { .x = 0, .y = 0 };
    t_data  data;
    
	if (argc)
		map_size(argv[1], &map);
    if (!map.matrix)
        return (print_error_and_return("Error\nFailed malloc for map.matrix.", 1));
    create_matrix(&map, argv[1]);
    if ( !check_walls(map) || dup_or_no_player(map) || !valid_characters(map)
        || !is_rectangular(map) || dup_or_no_exit(map) || !collectible(map))
        return (1);
    mlx.con = mlx_init();
    if (!mlx.con)
        return (print_error_and_return("Error\nFailed malloc for mlx.con.", 1));
    mlx.w = TILE_WIDTH * map.w;
    mlx.h = TILE_HEIGHT * map.h;
	mlx.win = mlx_new_window(mlx.con, mlx.w, mlx.h, mlx.title);
    if (!mlx.win)
    {
        mlx_destroy_display(mlx.con);
        free(mlx.con);
        return (1);
    }
    load_tiles(&map, &mlx, &img);
    fill_window_with_tiles(&map, &mlx, &img);
    data.mlx = mlx;
    data.map = map;
    data.img = img;
    mlx_key_hook(mlx.win, key_press, &data);
    mlx_hook(mlx.win, 17, 1L<<3, button_release, &mlx);
    mlx_loop(mlx.con);
    return (0);
}