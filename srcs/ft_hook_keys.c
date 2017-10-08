/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:06:15 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/08 11:24:57 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_hook_mouse_zoom(int key, int x, int y, t_map *map)
{
	if (key == BUTTON1)
	{
		map->mousestop = 1;
		map->zoom *= 1.2;
		map->posx += ((float)x - ((float)map->width / 2)) / ((float)map->width
			* map->zoom);
		map->posy += ((float)y - ((float)map->width / 2)) / ((float)map->length
			* map->zoom);
		ft_goto_id(map);
	}
	if (key == BUTTON2)
	{
		if (map->zoom > 1)
		{
			map->zoom *= .9;
			map->posx += ((float)x - ((float)map->width / 2)) / ((float)map->width
			* map->zoom);
			map->posy += ((float)y - ((float)map->width / 2)) / ((float)map->length
			* map->zoom);
			ft_goto_id(map);
		}
	}
	return (0);
}

int		ft_mouse_move_hook(int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->length ||
			map->mousestop == 1)
		return (0);
	map->cRe = (float)x / ((float)map->width
			* map->zoom * 1.5);
	map->cIm = (float)y / ((float)map->length
			* map->zoom * 1.5);
		ft_goto_id(map);
		return (0);
}


int		ft_hook_basic_keys(int key, t_map *map)
{
	if (key == KEY_ESCAPE)
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
