/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:09:25 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/12 10:30:16 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void   map_size(char *map_name, t_map *map)
{
    int     fd;
    char    *line;
    int     height;

    fd = open(map_name, O_RDONLY);
    line = get_next_line(fd);
    map->w = ft_strlen(line) - 1;
    height = 1;
    while (line)
    {
        line = get_next_line(fd);
        if (line)
            height++;
    }
    map->h = height;
    map->matrix = malloc(map->h * sizeof(char *));
    close(fd);
    free(line);
}

int create_matrix(t_map *map, char *map_name)
{
    int     fd;
    int     i;
    char    *line;

    fd = open(map_name, O_RDONLY);
    line = get_next_line(fd);

    i = 0;
    while(line)
    {
        map->matrix[i] = line;
        line = get_next_line(fd);
        i++;
    }
    close(fd);
    if ( !check_walls(*map) || dup_or_no_player(*map) || !valid_characters(*map)
    || !is_rectangular(*map) || dup_or_no_exit(*map) || !collectible(*map))
        return (0);
    else
        return (1);
}

void	load_tiles(t_map *map, t_mlx *mlx, t_img *img)
{
	map->tiles.grass = mlx_xpm_file_to_image(mlx->con, "sprites/grass.xpm", &img->w, &img->h);
    map->tiles.tree = mlx_xpm_file_to_image(mlx->con, "sprites/tree.xpm", &img->w, &img->h);
    map->tiles.mushrooms = mlx_xpm_file_to_image(mlx->con, "sprites/mushrooms.xpm", &img->w, &img->h);
    map->tiles.exit = mlx_xpm_file_to_image(mlx->con, "sprites/exit.xpm", &img->w, &img->h);
    map->tiles.wizard = mlx_xpm_file_to_image(mlx->con, "sprites/wizard.xpm", &img->w, &img->h);
}

void	get_image(char c, t_img *img, t_tiles *tiles)
{
	if (c == '0')
        img->img = tiles->grass;
	else if (c == '1')
		img->img = tiles->tree;
	else if (c == 'C')
		img->img = tiles->mushrooms;
	else if (c == 'E')
		img->img = tiles->exit;
	else if (c == 'P')
		img->img = tiles->wizard;
}