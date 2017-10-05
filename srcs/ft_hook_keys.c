/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:06:15 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/05 20:53:36 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_hook_pos_keys(int key, t_map *map)
{
	if (key == KEY_W)
	{
	//	map->blackscreen = mlx_new_image(map->mlx, map->width,
	//			map->length);
	//	mlx_put_image_to_window(map->mlx, map->win, map->blackscreen,
	//			0, 0);
			map->posy -= 10;
			ft_map_setup(map);
	}
	if (key == KEY_S)
	{
	//	map->blackscreen = mlx_new_image(map->mlx, map->width,
	//			map->length);
	//	mlx_put_image_to_window(map->mlx, map->win, map->blackscreen,
	//			0, 0);
		map->posy += 10;
		ft_map_setup(map);
	}
	return(0);
}

static int		ft_hook_pos_keys2(int key, t_map *map)
{
	if (key == KEY_A)
	{
	//	map->blackscreen = mlx_new_image(map->mlx, map->width,
	//			map->length);
	//	mlx_put_image_to_window(map->mlx, map->win, map->blackscreen,
	//			0, 0);
		map->posx -= 10;
		ft_map_setup(map);
	}
	if (key == KEY_D)
	{
	//	map->blackscreen = mlx_new_image(map->mlx, map->width,
	//			map->length);
	//	mlx_put_image_to_window(map->mlx, map->win, map->blackscreen,
	//			0, 0);
		map->posx += 10;
		ft_map_setup(map);
	}
	return (0);
}

int		ft_hook_mouse_zoom(int key, int x, int y, t_map *map)
{
	if (key == BUTTON1)
	{
	//	map->blackscreen = mlx_new_image(map->mlx, map->width,
	//			map->length);
	//	mlx_put_image_to_window(map->mlx, map->win, map->blackscreen,
	//			0, 0);
		x = x;
		y = y;
		map->zoom *= 1.1;
		ft_map_setup(map);
	}
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
	ft_hook_pos_keys(key, map);
	ft_hook_pos_keys2(key, map);
	return (0);
}
