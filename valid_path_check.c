/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:35:26 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/19 12:58:48 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_field(t_checker *checker, char **grid, int i, int j)
{
	char	current_field;

	current_field = grid[i][j];
	grid[i][j] = 'x';
	if (current_field == 'C')
		checker->num_collectibles--;
	else if (current_field == 'E')
	{
		checker->exit_found = 1;
		return ;
	}
	if (grid[i - 1][j] != '1' && grid[i - 1][j] != 'x')
		check_field(checker, grid, i - 1, j);
	if (grid[i][j - 1] != '1' && grid[i][j - 1] != 'x')
		check_field(checker, grid, i, j - 1);
	if (grid[i][j + 1] != '1' && grid[i][j + 1] != 'x')
		check_field(checker, grid, i, j + 1);
	if (grid[i + 1][j] != '1' && grid[i + 1][j] != 'x')
		check_field(checker, grid, i + 1, j);
}

void	free_grid(char **grid, int n_rows)
{
	int	i;

	i = 0;
	while (i < n_rows)
		free(grid[i++]);
	free(grid);
}

int	is_valid_path(t_map *map)
{
	char		**grid_copy;
	t_checker	checker;
	int			i;

	checker.num_collectibles = map->n_collectibles;
	checker.exit_found = 0;
	grid_copy = malloc(map->rows * sizeof(char *));
	if (!grid_copy)
		return (1);
	i = 0;
	while (i < map->rows)
	{
		grid_copy[i] = malloc(map->columns * sizeof(char));
		copy(grid_copy[i], map->grid[i], map->columns);
		i++;
	}
	check_field(&checker, grid_copy, map->y_player, map->x_player);
	free_grid(grid_copy, map->rows);
	if (checker.num_collectibles > 0 || checker.exit_found == 0)
		return (0);
	return (1);
}
