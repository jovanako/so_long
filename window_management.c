/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:06:46 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/18 19:41:54 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_tiles(t_data *data)
{
	int		w;
	int		h;

	w = TILE_WIDTH;
	h = TILE_HEIGHT;
	data->tiles = malloc(sizeof(t_tiles));
	data->tiles->grass = 
		mlx_xpm_file_to_image(data->mlx->con, "textures/grass.xpm", &w, &h);
    data->tiles->tree =
		mlx_xpm_file_to_image(data->mlx->con, "textures/tree.xpm", &w, &h);
    data->tiles->mushrooms =
		mlx_xpm_file_to_image(data->mlx->con, "textures/mushrooms.xpm", &w, &h);
    data->tiles->exit =
		mlx_xpm_file_to_image(data->mlx->con, "textures/exit.xpm", &w, &h);
    data->tiles->wizard =
		mlx_xpm_file_to_image(data->mlx->con, "textures/wizard.xpm", &w, &h);
}

void	*get_image(char c, t_tiles *tiles)
{
	if (c == '0')
        return (tiles->grass);
	else if (c == '1')
		return (tiles->tree);
	else if (c == 'C')
		return (tiles->mushrooms);
	else if (c == 'E')
		return (tiles->exit);
	return (tiles->wizard);
}

void	fill_window_with_tiles(t_mlx *mlx, t_map *map, t_tiles *tiles)
{
	int		i;
	int		j;
	void	*img;
    
    i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
            img = get_image(map->grid[i][j], tiles);
            mlx_put_image_to_window(mlx->con, mlx->win, img, j * TILE_WIDTH, i * TILE_HEIGHT);
            j++;
		}
		i++;
	}
}

void	display_exit_message()
{
	
	write (1, "You win! Press ESC to exit.", 27);
	write (1, "\n", 1);
}

