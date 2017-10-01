# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeletan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/16 07:30:41 by adeletan          #+#    #+#              #
#    Updated: 2017/09/25 20:37:23 by rpagot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

LIBFT = libft/libft.a

CFLAGS := -L./minilibx_macos -lmlx -framework OpenGl -framework AppKit -g3 -fsanitize=address

INCLUDES := -I./minilibx_macos -I./includes -I./libft

SRCS := main.c \
		ft_parse.c \
		ft_map.c

SRCSP := $(addprefix ./srcs/,  $(SRCS))
OBJS = $(SRCS:.c=.o)
OBJSP = $(addprefix ./objs/, $(SRCS:.c=.o))
OBJS = $(SRCSP:.c=.o)

all : lib $(NAME)

lib :
	make -C libft/
	make -C minilibx_macos/


$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCLUDES)

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
