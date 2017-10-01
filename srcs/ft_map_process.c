/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 01:58:05 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/01 07:30:34 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_map_process(t_fract *fract)
{
	if (!(map->image = mlx_new_image(map->mlx, map->width, map->length))
			return ;
	map->addr = mlx_get_data_addr(map->image, &map->bpp, &map->length);


