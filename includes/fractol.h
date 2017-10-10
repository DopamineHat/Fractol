/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 12:22:24 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/10 01:16:15 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>

# include "libft.h"
# include "key_codes_macos.h"
# include "events.h"

typedef struct	s_map
{
	size_t	itermax;
	int		mousestop;
	int		id;
	int		width;
	int		length;
	int		*mlx;
	int		*win;
	int		*blackscreen;
	int		*image;
	int		bpp;
	int		endian;
	char	*addr;
	float	centerx;
	float	centery;
	float	zoom;
	float	cre;
	float	cim;
	float	vre;
	float	vim;
	float	lre;
	float	lim;
	float	posx;
	float	posy;
	int		iter;
	float	mr;
	float	mi;
}				t_map;

void			ft_burning_ship(int x, int y, int *addr, t_map *map);
void			ft_set_values(t_map *map);
int				ft_mouse_move_hook(int x, int y, t_map *map);
int				ft_hook_mouse_zoom(int key, int x, int y, t_map *map);
int				ft_hook_basic_keys(int key, t_map *map);
int				ft_goto_id(t_map *map);
void			ft_map_display(t_map *map);
#endif
