/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:11:54 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/13 13:46:24 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	move_right(t_map *map)
{
	char	target_tile;
	
	target_tile = map->grid[map->y_player][map->x_player + 1];	
	if (target_tile != '1' && target_tile != 'E')
	{
		map->grid[map->y_player][map->x_player] = '0';
		map->grid[map->y_player][map->x_player + 1] = 'P';
		map->x_player++;
	}
	return (target_tile);
}

char	move_left(t_map *map)
{
	char	target_tile;
	
	target_tile = map->grid[map->y_player][map->x_player - 1];	
	if (target_tile != '1' && target_tile != 'E')
	{
		map->grid[map->y_player][map->x_player] = '0';
		map->grid[map->y_player][map->x_player - 1] = 'P';
		map->x_player--;
	}
	return (target_tile);
}

char	move_up(t_map *map)
{
	char	target_tile;
	
	target_tile = map->grid[map->y_player - 1][map->x_player];	
	if (target_tile != '1' && target_tile != 'E')
	{
		map->grid[map->y_player][map->x_player] = '0';
		map->grid[map->y_player - 1][map->x_player] = 'P';
		map->y_player--;
	}
	return (target_tile);
}

char	move_down(t_map *map)
{
	char	target_tile;
	
	target_tile = map->grid[map->y_player + 1][map->x_player];	
	if (target_tile != '1' && target_tile != 'E')
	{
		map->grid[map->y_player][map->x_player] = '0';
		map->grid[map->y_player + 1][map->x_player] = 'P';
		map->y_player++;
	}
	return (target_tile);
}