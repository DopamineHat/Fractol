/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 11:34:12 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/08 16:53:02 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_set_burning_ship(t_map *map, int x, int y)
{
	map->lRe = 0;
	map->lIm = 0;
	map->vIm = 0;
	map->vRe = 0;
	map->mR = 6 * (x - map->width * .5) / (map->zoom * map->width)
		+ map->posx;
	map->mI = 5 * (y - map->width * .5) / (map->zoom * map->width)
		+ .3
		+ map->posy;
}

void		ft_burning_ship(int x, int y, int *addr, t_map *map)
{
	int i;

	while (y < map->length)
	{
		while(x < map->width)
		{
			i = -1;
			ft_set_burning_ship(map, x, y);
			while (map->vRe * map->vRe + map->vIm
					* map->vIm < 4 && ++i < map->iter)
			{
				map->lRe = map->vRe;
				map->lIm = map->vIm;
				map->vRe = fabsf(map->lRe * map->lRe - map->lIm * map->lIm) + map->mR;
				map->vIm = 2 * fabsf(map->lRe * map->lIm) + map->mI;
			}
			addr[x + y * map->width] = (i << 19) + (i << 9) + i;
			x++;
		}
		y++;
		x = 0;
	}
}

