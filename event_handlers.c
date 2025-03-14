/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:39:35 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/14 08:06:05 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_program(t_data *data)
{
	if (data->map->grid[0][0])
		free_map(data->map);
	if (data->mlx->win)
	{
		mlx_destroy_window(data->mlx->con, data->mlx->win);
		mlx_destroy_image(data->mlx->con, data->tiles.grass);
		mlx_destroy_image(data->mlx->con, data->tiles.tree);
		mlx_destroy_image(data->mlx->con, data->tiles.mushrooms);
		mlx_destroy_image(data->mlx->con, data->tiles.exit);
		mlx_destroy_image(data->mlx->con, data->tiles.wizard);
		free(data->mlx->con);
	}
}

int		end_program_and_return(t_data *data)
{
	end_program(data);
	return (1);
}

static void	display_move_count(int n)
{
	char	*moves_str;

	moves_str = ft_itoa(n);
	
	write (1, "Number of moves: ", 17);
	write (1, moves_str, ft_strlen(moves_str));
	write (1, "\n", 1);
}

void	handle_move(char field, t_data *data)
{
	if (field == 'C' || field == '0')
	{
		data->n_moves++;
		display_move_count(data->n_moves);
		fill_window_with_tiles(data->mlx, data->map, &(data->tiles));
	}
	if (field == 'C')
		data->map->n_collectibles--;
	if (field == 'E' && data->map->n_collectibles == 0)
	{
		data->map->frozen = 1;
		exit_handler(data->mlx, data->map, &(data->tiles));
		display_exit_message();
	}
}

int		key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		end_program(data);
		exit(0);
	}
	else if (!(data->map->frozen))
	{
		if (keycode == 65363 || keycode == 100)
			handle_move(move_right(data->map), data);
		else if (keycode == 65361 || keycode == 97)
			handle_move(move_left(data->map), data);
		else if (keycode == 65362 || keycode == 119)
			handle_move(move_up(data->map), data);
		else if (keycode == 65364 || keycode == 115)
			handle_move(move_down(data->map), data);		
	}
	return (0);
}