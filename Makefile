# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/07 03:17:48 by rpagot            #+#    #+#              #
#    Updated: 2017/10/08 12:57:47 by rpagot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

LIBFT = libft/libft.a

CFLAGS := -Ofast -march=native
LCFLAGS := -L./minilibx_macos -lmlx -framework OpenGl -framework AppKit -Ofast -march=native

INCLUDES := -I./minilibx_macos -I./includes -I./libft

SRCS := main.c \
		ft_map_process.c \
		ft_hook_keys.c \
		ft_burning_ship.c

SRCSP := $(addprefix ./srcs/,  $(SRCS))
OBJS = $(SRCS:.c=.o)
OBJSP = $(addprefix ./objs/, $(SRCS:.c=.o))
OBJS = $(SRCSP:.c=.o)

all : lib $(NAME)

lib :
	make -C libft/
	make -C minilibx_macos/


$(NAME): $(OBJS)
	gcc $(LCFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCLUDES)

%.o : %.c
	gcc $(CFLAGS)  $(INCLUDES) -c -o $@ $<

clean :
	make -C libft/ clean
	make -C minilibx_macos/ clean
	rm -rf $(OBJSP) $(OBJS)

fclean : clean
	make -C libft/ fclean
	rm -rf $(NAME)

re : fclean all
