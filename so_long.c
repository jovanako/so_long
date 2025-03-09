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
    map.w = ft_strlen(line) - 1;
    height = 1;
    while (line)
    {
        line = get_next_line(fd);
        if (line)
            height++;
    }
    map.h = height;
    map.matrix = malloc(map.h * sizeof(char *));
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

int     main(int argc, char *argv[])
{
    t_mlx   mlx = { .title = "Collect the mushrooms, Miraculix!" };
    t_img   img = { .w = TILE_WIDTH, .h = TILE_HEIGHT };
    t_map   map;
    
	if (argc)
		map = map_size(argv[1]);
    if (!map.matrix)
        return (print_error_and_return("Error\nFailed malloc for map.matrix.", 1));
    map.matrix = create_matrix(map, argv[1]);
    if ( !check_walls(map) || dup_or_no_player(map) || !valid_characters(map)
        || !is_rectangular(map) || dup_or_no_exit(map) || !collectible(map))
        return (1);
    mlx.con = mlx_init();
    if (!mlx.con)
        return (1);
    mlx.win = create_and_fill_window(mlx, map, img);
    if (!mlx.win)
    {
        mlx_destroy_display(mlx.con);
        free(mlx.con);
        return (1);
    }
    mlx_loop(mlx.con);

   // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    // mlx_destroy_display(mlx.con);
    // mlx_destroy_window(mlx.con, mlx.win);
    // mlx_destroy_image(mlx.con, img.img);
    // free(mlx.con);
    // free(mlx.win);
    // free(img.img);
    return (0);
}