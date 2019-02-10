/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:30:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/11 00:27:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# ifdef __APPLE__
#  include "keys_macos.h"

#  define WIN_X		2000
#  define WIN_Y		1000
# endif

# ifdef __linux__
#  include "keys_linux.h"

#  define WIN_X		1280
#  define WIN_Y		720
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
_ULL;

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

typedef struct	s_ray_caster
{
	fpoint	pos;
	fpoint	dir;
	fpoint	plane;
	double	xcamera;
	fpoint	ray_dir;
	point	map;
	fpoint	side_dist;
	fpoint	absdist;
	double	pwd;
	point	step;
	bool	is_hit;
	bool	is_side;
	int		hline;
	int		draw_start;
	int		draw_end;
	int		current_color;
}				t_rc;

typedef struct	s_wolf3d_environment
{
	t_mlx		*mlx;
	t_isr		*isr;
	t_map		*map;
	t_rc		*rc;
}				t_env;

bool			wolf_init(t_env *env);

bool			wolf_readnsave(string map_name, t_env *env);

void			wolf_rendering(t_env *env);

int				wolf_key_hooks(int key, t_env *env);
int				wolf_killwindow(t_env *env);

void			wolf_free(t_env **env);
void			wolf_free_map(t_map **map);

#endif
