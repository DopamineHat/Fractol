/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 01:58:05 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/05 21:08:51 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	ft_map_process(int x, int y, int i, int *addr, t_map *map)
{
	while (y < map->length)
	{
		while(x < map->width)
		{
			map->vRe = 3 * (x - map->width * .5) / (map->zoom * map->width) ;
			map->vIm = 2 * (y - map->length * .5) / (map->zoom * map->length);
			i = -1;
			while (++i < map->iter)
			{
				map->lRe = map->vRe;
				map->lIm = map->vIm;
				map->vRe = map->lRe * map->lRe - map->lIm * map->lIm + map->cRe;
				map->vIm = map->lRe * map->lIm * 2 + map->cIm;
				if(map->vRe * map->vRe + map->vIm * map->vIm > 4)
					break;
			}
			addr[x + y * map->width] = (i*8 << 16) + (i*2 << 8) + i;
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_map_setup(t_map *map)
{
	int size_line;
	int x;
	int y;
	int i;
	int *addr;

	x = 0;
	y = 0;
	i = 0;
	if (!(map->image = mlx_new_image(map->mlx, map->width, map->length)))
			return ;
	map->addr = mlx_get_data_addr(map->image, &map->bpp, &size_line, &map->endian);
	addr = (int *)map->addr;
	ft_map_process(x, y, i, addr, map);
	mlx_put_image_to_window(map->mlx, map->win, map->image, 0, 0);
}
