/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:54:11 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/04 13:54:14 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map   map_size(char *map_name)
{
    int     fd;
    t_map   map;
    char    *line;
    int     height;

    fd = open(map_name, O_RDONLY);
    line = get_next_line(fd);
    map.width = ft_strlen(line) - 1;
    height = 1;
    while (line)
    {
        line = get_next_line(fd);
        if (line)
            height++;
    }
    map.height = height;
    map.matrix = malloc(map.height * sizeof(char *));
    close(fd);
    free(line);
    return (map);
}

static char **create_matrix(t_map map, char *map_name)
{
    int     fd;
    int     i;
    char    *line;

    fd = open(map_name, O_RDONLY);
    line = get_next_line(fd);

    i = 0;
    while(line)
    {
        map.matrix[i] = line;
        line = get_next_line(fd);
        i++;
    }
    close(fd);
    return (map.matrix);
}

static void	fill_window_with_tiles(t_map map, t_mlx mlx, t_img img)
{
	int		i;
	int		j;

	map.y = 0;
	i = 0;
	while (map.y < mlx.height)
	{
		map.x = 0;
		j = 0;
		while (j < map.width)
		{
			img.img = mlx_xpm_file_to_image(mlx.connection, this_tile(map.matrix[i][j]), &img.width, &img.height);
            mlx_put_image_to_window(mlx.connection, mlx.window, img.img, map.x, map.y);
            map.x += img.width;
            j++;
		}
		map.y += img.height;
		i++;
	}
}

int     main(int argc, char *argv[])
{
    t_mlx   mlx;
    t_img   img = { .width = TILE_WIDTH, .height = TILE_HEIGHT };
    t_map   map;
    
	if (argc)
		map = map_size(argv[1]);
    if (!map.matrix)
        return (1);
    map.matrix = create_matrix(map, argv[1]);
    if (!check_walls(map) || dup_or_no_player(map) || dup_or_no_exit(map)
        || !is_rectangular(map) || !collectible_exists(map))
        return (1);
    mlx.connection = mlx_init();
    if (!mlx.connection)
        return (1);
    mlx.width = TILE_WIDTH * map.width;
    mlx.height = TILE_HEIGHT * map.height;
    mlx.window = mlx_new_window(mlx.connection, mlx.width, mlx.height, "Collect the mushrooms, Miraculix!");
    if (!mlx.window)
    {
        mlx_destroy_display(mlx.connection);
        free(mlx.connection);
        return (1);
    }
    fill_window_with_tiles(map, mlx, img);
    mlx_loop(mlx.connection);

   // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    // mlx_destroy_display(data.connection);
    // mlx_destroy_window(data.connection, data.window);
    // mlx_destroy_image(data.connection, data.img.img);
    // free(data.connection);
    // free(data.window);
    // free(data.img.img);
    return (0);
}