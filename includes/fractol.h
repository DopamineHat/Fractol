#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "libft.h"
#include "key_codes_macos.h"
#include "events.h"

typedef struct	s_map
{
	int		width;
	int		length;
	int		*mlx;
	int		*win;
	int		*blackscreen;
	int		*image;
	int		bpp;
	int		endian;
	char	*addr;
	float	zoom;
	float	cRe;
	float	cIm;
	float	vRe;
	float	vIm;
	float	lRe;
	float	lIm;
	int		posx;
	int		posy;
	int		iter;
}				t_map;

int				ft_hook_mouse_zoom(int key, int x, int y, t_map *map);
int				ft_hook_basic_keys(int key, t_map *map);
void			ft_set_values(t_map *map);
void			ft_map_setup(t_map *map);
void			ft_map_display(t_map *map);
#endif
