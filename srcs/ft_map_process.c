/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 01:58:05 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/08 16:49:16 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_julia_process(int x, int y, int *addr, t_map *map)
{
	int i;

	while (y < map->length)
	{
		x = -1;
		while(++x < map->width)
		{
			map->vRe = 3 * (x - map->width * .5) / (map->zoom * map->width)
				+ map->posx;
			map->vIm = 2 * (y - map->length * .5) / (map->zoom * map->length)
				+ map->posy;
			i = -1;
			while (++i < map->iter)
			{
				map->lRe = map->vRe;
				map->lIm = map->vIm;
				map->vRe = map->lRe * map->lRe - map->lIm * map->lIm 
					+ map->cRe;
				map->vIm = map->lRe * map->lIm * 2 + map->cIm;
				if(map->vRe * map->vRe + map->vIm * map->vIm > 4)
					break;
			}
			addr[x + y * map->width] = (i << 19) + (i << 9) + i;
		}
		y++;
	}
}

static	void	ft_set_mandelbroot_values(t_map *map, int x, int y)
{
	map->lRe = 0;
	map->lIm = 0;
	map->vRe = 0;
	map->vIm = 0;
	map->mR = 4 * (x - map->width * .5) / (map->zoom * map->width)
		+ map->posx;
	map->mI = 3 * (y - map->width * .5) / (map->zoom * map->width)
		+ .3
		+ map->posy;
}

static	void	ft_mandelbroot_process(int x, int y, int *addr,
		t_map *map)
{
	int i;

	while (y < map->length)
	{
		while(x < map->width)
		{
			i = -1;
			ft_set_mandelbroot_values(map, x, y);
			while (map->vRe * map->vRe + map->vIm
					* map->vIm < 4 && ++i < map->iter)
			{
				map->lRe = map->vRe;
				map->lIm = map->vIm;
				map->vRe = map->lRe * map->lRe - map->lIm * map->lIm + map->mR;
				map->vIm = 2 * map->lRe * map->lIm + map->mI;
			}
			addr[x + y * map->width] = (i << 19) + (i << 9) + i;
			x++;
		}
		y++;
		x = 0;
	}
}

int			ft_goto_id(t_map *map)
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
			return (1);
	map->addr = mlx_get_data_addr(map->image, &map->bpp,
			&size_line, &map->endian);
	addr = (int *)map->addr;
	if (map->id == 0)
		ft_julia_process(x, y, addr, map);
	if (map->id == 1)
		ft_mandelbroot_process(x, y, addr, map);
	if (map->id == 2)
		ft_burning_ship(x, y, addr, map);
	mlx_put_image_to_window(map->mlx, map->win, map->image, 0, 0);
	return (0);
}
