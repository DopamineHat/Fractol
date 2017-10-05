/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:11:46 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/06 00:38:57 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_parse_name(t_map *map, char *name)
{
	if (!(ft_strcmp(name, "julia")))
		map->id = 0;
	if (!(ft_strcmp(name, "mandelbroot")))
		map->id = 1;
}
static void	ft_set_values(t_map *map)
{
	map->width = 500;
	map->length = 500;
	map->mlx = mlx_init();
	map->zoom = 1;
	map->win = mlx_new_window(map->mlx, map->width,
			map->length, "Fractol");
	map->cRe = -.7;
	map->cIm = .27;
	map->iter = 200;
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
	ft_goto_id(map);
	mlx_hook(map->win, KEYPRESS, KEYRELEASE, &ft_hook_basic_keys, map);
	mlx_mouse_hook(map->win, &ft_hook_mouse_zoom, map);
	mlx_loop(map->mlx);
	return (0);
}
