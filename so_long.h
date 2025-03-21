/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:14:45 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/21 16:43:50 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define GNL_BUFFER_SIZE 10
# define TILE_HEIGHT 45
# define TILE_WIDTH 45

typedef struct s_mlx
{
	void	*con;
	void	*win;
	char	*title;
}				t_mlx;

typedef struct s_tiles
{
	void	*grass;
	void	*tree;
	void	*mushrooms;
	void	*exit;
	void	*wizard;
}				t_tiles;

typedef struct s_map
{
	int		columns;
	int		rows;
	char	**grid;
	int		x_player;
	int		y_player;
	int		n_collectibles;
	int		frozen;
}				t_map;

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
}				t_img;

typedef struct s_data
{
	t_mlx	*mlx;
	t_map	*map;
	t_tiles	*tiles;
	int		n_moves;
}				t_data;

typedef struct s_checker
{
	int		num_collectibles;
	int		exit_found;
}				t_checker;

char	*get_next_line(int fd);
int		ft_strlen(char *str);
void	copy(char *dst, char *src, int n);
char	*ft_itoa(int n);
int		valid_mapname_extension(char *s);
int		load_map(int n, char *map_name, t_map *map);
int		perror_and_return(char *error_message, int n);
int		check_walls(t_map *map);
int     is_rectangular(t_map *map);
int		valid_characters(t_map *map);
int		dup_or_no_player(t_map *map);
int		dup_or_no_exit(t_map *map);
int		is_valid_path(t_map *map);
void	load_tiles(t_data *data);
void	*get_image(char c, t_tiles *tiles);
void	fill_window_with_tiles(t_mlx *mlx, t_map *map, t_tiles *tiles);
char	move_right(t_map *map);
char	move_left(t_map *map);
char	move_up(t_map *map);
char	move_down(t_map *map);
void	handle_move(char field, t_data *data);
void	exit_handler(t_mlx *mlx, t_map *map, t_tiles *tiles);
void	free_map_with_grid(t_map *map);
int		free_map_and_return(t_map *map);
void	cleanup(t_data *data);
int		end_program_and_return(t_data *data);
int		key_press(int keycode, t_data *data);
void	display_exit_message(void);

#endif
