/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 11:34:12 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/09 12:17:27 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_set_burning_ship(t_map *map, int x, int y)
{
	map->lre = 0;
	map->lim = 0;
	map->vim = 0;
	map->vre = 0;
	map->mr = 6 * (x - map->width * .5) / (map->zoom * map->width)
		+ map->posx;
	map->mi = 5 * (y - map->width * .5) / (map->zoom * map->width)
		+ .3
		+ map->posy;
}

void			ft_burning_ship(int x, int y, int *addr, t_map *map)
{
	int i;

	while (y < map->length)
	{
		while (x < map->width)
		{
			i = -1;
			ft_set_burning_ship(map, x, y);
			while (map->vre * map->vre + map->vim
					* map->vim < 4 && ++i < map->iter)
			{
				map->lre = map->vre;
				map->lim = map->vim;
				map->vre = fabsf(map->lre * map->lre - map->lim * map->lim)
					+ map->mr;
				map->vim = 2 * fabsf(map->lre * map->lim) + map->mi;
			}
			addr[x + y * map->width] = (i << 19) + (i << 9) + i;
			x++;
		}
		y++;
		x = 0;
	}
}
