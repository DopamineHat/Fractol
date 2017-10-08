/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 11:34:12 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/08 15:17:14 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		ft_set_burning_ship(t_map *map)
{
	map->lRe = 0;
	map->lIm = 0;
}

void		ft_burning_ship(int x, int y, int *addr, t_map *map)
{
	int i;

	while (y < map->length)
	{
		x = -1;
		while (++x < map->width)
		{
			map->cRe = (x - map->width / 2) / (.5 * map->zoom * map->width)
				+ map->posx;
			map->cIm = (y - map->width / 2) / (.5 * map->zoom * map->width)
				+ map->posy;
			i = -1;
//			printf("%f", map->cRe);
			while (++i < map->iter && map->lRe * map->lRe + map->lIm
					* map->lIm < 4)
			{
//	printf("%f", map->vRe);
				map->vRe = map->lRe * map->lRe - map->lIm * map->lIm
					- map->cRe;
				map->vIm = 2 * fabsf(map->lIm) * fabsf(map->lRe) + map->cIm;
				map->lRe = map->vRe;
//				printf("%f", map->lRe * map->lRe + map->lIm
//					* map->lIm);

			}
			printf("%d", i);
			addr[x + y * map->width] = (i << 19) + (i << 9) + i;
//			printf("%d", map->lRe * map->lRe + map->lIm
//					* map->lIm < 4);
		}
		y++;
	}
}
