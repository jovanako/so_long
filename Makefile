# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 12:44:57 by jkovacev          #+#    #+#              #
#    Updated: 2025/03/21 17:06:49 by jkovacev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -I/usr/local/include

SRCS = so_long.c \
		gnl_utils.c \
		get_next_line.c \
		map.c \
		invalid_map_checks1.c \
		invalid_map_checks2.c \
		valid_path_check.c \
		window_management.c \
		movement_handlers.c \
		ft_itoa.c \
		event_handlers.c

OBJS = $(SRCS:.c=.o)

DEPS = so_long.h

MLX_DIR = ../mlx_linux

all: $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(OBJS) -lmlx -L/usr/local/lib -lXext -lX11 -o $(NAME)

%.o: %.c $(DEPS)
		$(CC) $(CFLAGS) -c -o $@ $<

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
