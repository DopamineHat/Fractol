#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "libft.h"

typedef struct	s_fract
{
	int		width;
	int		length;
	int		*mlx;
	int		*win;
	int		*image;
	int		bpp;
	int		endian;
	char	*addr;
	int		zoom;
	float	cRe;
	float	cIm;
	int		posx;
	int		posy;
	int		iter;
}				t_map

void			ft_set_values(t_fract *fract);
void			ft_map_process(t_fract *fract);
void			ft_map_display(t_fract *fract);
