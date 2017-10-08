/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:11:46 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/08 12:51:50 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_parse_name(t_map *map, char *name)
{
	if (!(ft_strcmp(name, "julia")))
		map->id = 0;
	if (!(ft_strcmp(name, "mandelbrot")))
		map->id = 1;
	if (!(ft_strcmp(name, "burningship")))
		map->id = 2;
}

static void	ft_set_window(t_map *map)
{
	map->mousestop = 0;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->width,
			map->length, "Fractol");
}

void		ft_set_values(t_map *map)
{
	map->width = 1600;
	map->length = 1200;
	map->zoom = 1;
	map->cRe = -.7;
	map->cIm = .27015;
	map->iter = 400;
	map->posx = 0;
	map->posy = 0;
}

int		main(int argc, char **argv)
{
	t_map	*map;

	if (!(argc == 2))
	{
		ft_putstr_fd("Fractol: invalid arguments.\n", 2);
		return (1);
	}
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (1);
	ft_parse_name(map, argv[1]);
	ft_set_values(map);
	ft_set_window(map);
	ft_goto_id(map);
	mlx_hook(map->win, MOTIONNOTIFY, POINTERMOTIONMASK, &ft_mouse_move_hook
			, map);
	mlx_hook(map->win, KEYPRESS, KEYRELEASE, &ft_hook_basic_keys, map);
	mlx_mouse_hook(map->win, &ft_hook_mouse_zoom, map);
	mlx_loop(map->mlx);
	return (0);
}
