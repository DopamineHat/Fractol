/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:11:46 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/01 02:07:28 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_values(t_fract *fract)
{
	map->width = 1000;
	map->length = 1000;
	map->mlx = mlx_init();
	map->zoom = 1;
	map->win = mlx_new_window(map->mlx, map->width,
			map->length, "Fractol");
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
	ft_set_values(map);
	ft_map_process(map);
	ft_map_display(map);
	return (0);
}
