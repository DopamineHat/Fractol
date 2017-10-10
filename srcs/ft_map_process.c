/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 01:58:05 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/10 03:40:56 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_julia_process(int x, int y, int *addr, t_map *map)
{
	int i;

	while (y < map->length)
	{
		x = -1;
		while (++x < map->width)
		{
			map->vre = x * map->zoom / map->width + map->centerx;
			map->vim = y * map->zoom / map->width + map->centery;
			i = -1;
			while (++i < map->iter
					&& map->vre * map->vre + map->vim * map->vim < 4)
			{
				map->lre = map->vre;
				map->lim = map->vim;
				map->vre = map->lre * map->lre - map->lim * map->lim
					+ map->cre;
				map->vim = map->lre * map->lim * 2 + map->cim;
			}
			addr[x + y * map->width] = (i << 19) + (i << 9) + i;
		}
		y++;
	}
}

static	void	ft_set_mandelbroot_values(t_map *map, int x, int y)
{
	map->lre = 0;
	map->lim = 0;
	map->vre = 0;
	map->vim = 0;
	map->mr = x * map->zoom / map->width + map->centerx;
	map->mi = y * map->zoom / map->width + map->centery;
}

static	void	ft_mandelbroot_process(int x, int y, int *addr,
		t_map *map)
{
	int i;

	while (y < map->length)
	{
		while (x < map->width)
		{
			i = -1;
			ft_set_mandelbroot_values(map, x, y);
			while (map->vre * map->vre + map->vim
					* map->vim < 4 && ++i < map->iter)
			{
				map->lre = map->vre;
				map->lim = map->vim;
				map->vre = map->lre * map->lre - map->lim * map->lim + map->mr;
				map->vim = 2 * map->lre * map->lim + map->mi;
			}
			addr[x + y * map->width] = (i << 19) + (i << 9) + i;
			x++;
		}
		y++;
		x = 0;
	}
}

int				ft_goto_id(t_map *map)
{
	int size_line;
	int x;
	int y;
	int i;
	int *addr;

	x = 0;
	y = 0;
	i = 0;
	if (!(map->image = mlx_new_image(map->mlx, map->width, map->length))
				|| map->iter > map->itermax)
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
	if (map->mousestop == 1)
		map->iter *= 2;
	return (0);
}
