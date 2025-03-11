# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 20:09:31 by jkovacev          #+#    #+#              #
#    Updated: 2025/03/11 20:14:23 by jkovacev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -I/usr/local/include -O0

SRCS = so_long.c \
		gnl_utils.c \
		helpers.c \
		event_handlers.c \
		map.c \
		get_next_line.c \
		errors1.c \
		errors2.c

OBJS = $(SRCS:.c=.o)

DEPS = so_long.h

all: $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(OBJS) -lmlx -L/usr/local/lib -lXext -lX11 -lm -o $(NAME)

%.o: %.c $(DEPS)
		$(CC) $(CFLAGS) -c -o $@ $<

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
