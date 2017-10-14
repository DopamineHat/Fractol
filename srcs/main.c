/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:11:46 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/14 13:42:28 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_parse_name(t_map *map, char *av1, char *av2)
{
	if (!(ft_strcmp(av1, "julia")))
		map->id = 0;
	else if (!(ft_strcmp(av1, "mandelbrot")))
		map->id = 1;
	else if (!(ft_strcmp(av1, "burningship")))
		map->id = 2;
	else
		return (1);
	map->itermax = ft_atoi(av2);
	return (0);
}

static void	ft_set_window(t_map *map)
{
	map->mousestop = 0;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->width,
			map->length, "Fractol");
	map->centerx = -(float)(map->width) / 1000;
	map->centery = -(float)(map->length) / 1000;
}

void		ft_set_values(t_map *map)
{
	map->iter = 100;
	map->width = 2400;
	map->length = 1350;
	map->zoom = 5;
	map->cre = -.7;
	map->cim = .27015;
	map->posx = 0;
	map->posy = 0;
}

int			main(int argc, char **argv)
{
	t_map	*map;

	if (!(argc == 3))
	{
		ft_putstr_fd("Fractol: invalid arguments.\n", 2);
		return (1);
	}
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (1);
	if (ft_parse_name(map, argv[1], argv[2]))
	{
		ft_putstr_fd("Fractol: invalid argument. \n", 2);
		return (1);
	}
	ft_set_values(map);
	ft_set_window(map);
	mlx_hook(map->win, MOTIONNOTIFY, POINTERMOTIONMASK, &ft_mouse_move_hook
		, map);
	mlx_hook(map->win, KEYPRESS, KEYRELEASE, &ft_hook_basic_keys, map);
	mlx_mouse_hook(map->win, &ft_hook_mouse_zoom, map);
	ft_goto_id(map);
	mlx_loop(map->mlx);
	return (0);
}
