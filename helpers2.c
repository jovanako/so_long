/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:52:38 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/04 13:52:51 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*this_tile(char c)
{
	if (c == '0')
		return ("sprites/grass.xpm");
	else if (c == '1')
		return ("sprites/tree.xpm");
	else if (c == 'C')
		return ("sprites/mushrooms.xpm");
	else if (c == 'E')
		return ("sprites/exit.xpm");
	else if (c == 'P')
		return ("sprites/wizard.xpm");
	return (NULL);
}

int		find_c(char *s, char c, int len)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < len)
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int  print_error_and_return(char *error_message, int n)
{
    perror(error_message);
    return (n);
}

static void	fill_window_with_tiles(t_map map, t_mlx mlx, t_img img)
{
	int		i;
	int		j;

	map.y = 0;
	i = 0;
	while (map.y < mlx.h)
	{
		map.x = 0;
		j = 0;
		while (j < map.w)
		{
			img.img = mlx_xpm_file_to_image(mlx.con, this_tile(map.matrix[i][j]), &img.w, &img.h);
            mlx_put_image_to_window(mlx.con, mlx.win, img.img, map.x, map.y);
            map.x += img.w;
            j++;
		}
		map.y += img.h;
		i++;
	}
}

void	*create_and_fill_window(t_mlx mlx, t_map map, t_img img)
{
	mlx.w = TILE_WIDTH * map.w;
    mlx.h = TILE_HEIGHT * map.h;
	mlx.win = mlx_new_window(mlx.con, mlx.w, mlx.h, mlx.title);
    fill_window_with_tiles(map, mlx, img);
	return (mlx.win);
}	