/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:30:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/09 12:44:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# ifdef __APPLE__
#  include "macos_keys.h"
# endif

# ifdef __linux__
#  include "linux_keys.h"
# endif

# include "wolf3d_defines.h"
# include "wolf3d_errno.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <mlx.h>

enum	e_bool {false, true} __attribute__((packed));

typedef struct	s_point
{
	int	y;
	int	x;
}				t_p;

typedef struct	s_fpoint
{
	float	y;
	float	x;
}				t_fp;

_FPOINT;
_POINT;
_BOOL;
_IARR;
_ITAB;
_UINT;

typedef struct	s_matrix
{
	fpoint	pos;
	int		rgb;
}				t_matrix;

typedef struct	s_mlx
{
	pvoid	mlx;
	pvoid	win;
	pvoid	img;
	iarr	screen;
}				t_mlx;

typedef struct	s_isrender
{
	bool	is_render;
}				t_isr;

typedef struct	s_map
{
	itab	tab;
	itab	colors;
	int		xsize;
	int		ysize;
}				t_map;

typedef struct	s_fdf_environment
{
	t_mlx		*mlx;
	t_isr		*isr;
	t_map		*raw;
	t_matrix	**map;
	point		map_sizes;
}				t_env;

typedef struct	s_ray_caster
{
	fpoint	pos;
	fpoint	dir;
	fpoint	plane;
	float	rotate;
}				t_rc;

bool			wolf_init(t_env *env);

bool			wolf_readnsave(string map_name, t_env *env);
bool			wolf_convert_map_to_matrix(t_env *env);

void			wolf_rendering(t_env *env);

int				wolf_key_hooks(int key, t_env *env);
int				wolf_killwindow(t_env *env);

void			wolf_free(t_env *env);
void			wolf_free_matrix(t_matrix **m, int y);
void			wolf_free_map(t_map *map);

#endif
