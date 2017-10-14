/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:06:15 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/14 09:22:21 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_hook_mouse_zoom(int key, int x, int y, t_map *map)
{
	if (key == BUTTON1)
	{
		map->mousestop = 1;
		map->posx = (float)x / (float)map->width * map->zoom + map->centerx;
		map->posy = (float)y / (float)map->width * map->zoom + map->centery;
		map->zoom *= .8;
		map->centerx = .8 * (map->centerx - map->posx) + map->posx;
		map->centery = .8 * (map->centery - map->posy) + map->posy;
		map->iter = 100;
		ft_goto_id(map);
	}
	if (key == BUTTON2)
	{
		map->posx = (float)x / (float)map->width * map->zoom + map->centerx;
		map->posy = (float)y / (float)map->width * map->zoom + map->centery;
		map->zoom *= 1.5;
		map->centerx = 1.5 * (map->centerx - map->posx) + map->posx;
		map->centery = 1.5 * (map->centery - map->posy) + map->posy;
		map->iter = 100;
		ft_goto_id(map);
	}
	return (0);
}

int		ft_mouse_move_hook(int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->length)
		return (0);
	if (map->mousestop == 0)
	{
		map->cre = (float)x * map->zoom * .1 / ((float)map->width);
		map->cim = (float)y * map->zoom * .05 / ((float)map->width);
	}
	ft_goto_id(map);
	return (0);
}

int		ft_hook_basic_keys(int key, t_map *map)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(map->mlx, map->win);
		free(map);
		exit(EXIT_SUCCESS);
	}
	if (key == KEY_R)
	{
		ft_set_values(map);
		ft_goto_id(map);
	}
	return (0);
}
