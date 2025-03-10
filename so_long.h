/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:51:55 by jkovacev          #+#    #+#             */
/*   Updated: 2025/03/04 13:52:27 by jkovacev         ###   ########.fr       */
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

typedef struct  s_map
{
    int     w;
    int     h;
    int     x;
    int     y;
    char    **matrix;
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

char	*this_tile(char c);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
int	    find_new_line(char *s);
void	append(char **line_buf, char *read_buf, int bytes_read);
char	*ft_substr(char **s, int start, int len);
void	copy(char *dst, char *src, int n);
int		count_c(char *s, char c, int len);
int     check_walls(t_map map);
int     dup_or_no_player(t_map map);
int     dup_or_no_exit(t_map map);
int     is_rectangular(t_map map);
int     collectible(t_map map);
int     print_error_and_return(char *error_message, int n);
int		valid_characters(t_map map);
int		key_press(int keycode, t_mlx *mlx);
int		button_release(t_mlx *mlx);

#endif
