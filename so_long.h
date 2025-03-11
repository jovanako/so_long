/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:14:45 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/11 22:33:13 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# define BUFFER_SIZE 10
# define TILE_HEIGHT 45
# define TILE_WIDTH 45

typedef struct  s_mlx
{
    void    *con;
    void    *win;
    int     w;
    int     h;
    char    *title;
}               t_mlx;

typedef struct  s_tiles
{
    void    *grass;
    void    *tree;
    void    *mushrooms;
    void    *exit;
    void    *wizard;
}               t_tiles;

typedef struct  s_map
{
    int     w;
    int     h;
    int     x;
    int     y;
    int     x_player;
    int     y_player;
    char    **matrix;
    t_tiles tiles;
}               t_map;


typedef struct  s_img
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     w;
    int     h;
    int     endian;
}               t_img;

typedef struct  s_data
{
    t_mlx   mlx;
    t_map   map;
    t_img   img;
}               t_data;

void    map_size(char *map_name, t_map *map);
void    create_matrix(t_map *map, char *map_name);
void	load_tiles(t_map *map, t_mlx *mlx, t_img *img);
void	get_image(char c, t_img *img, t_tiles *tiles);
void	fill_window_with_tiles(t_map *map, t_mlx *mlx, t_img *img);
int		ft_strlen(char *str);
int	    find_new_line(char *s);
void	append(char **line_buf, char *read_buf, int bytes_read);
char	*ft_substr(char **s, int start, int len);
void	copy(char *dst, char *src, int n);
char	*get_next_line(int fd);
int     check_walls(t_map map);
int     dup_or_no_player(t_map map);
int     dup_or_no_exit(t_map map);
int     is_rectangular(t_map map);
int     collectible(t_map map);
int     print_error_and_return(char *error_message, int n);
int		valid_characters(t_map map);
int		key_press(int keycode, t_data *data);
int		button_release(t_mlx *mlx);
void 	move_right(t_data *data);
void	end_program(t_mlx mlx, t_img img);

#endif
