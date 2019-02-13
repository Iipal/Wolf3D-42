/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:30:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/13 22:02:28 by tmaluh           ###   ########.fr       */
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
# include <math.h>
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
	bool	is_boost_step;
	bool	is_textured;
	bool	is_press_mouse;
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
	fpoint	raydir;
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
}				t_rc;

typedef struct	s_mouse
{
	int	last;
	int	curr;
}				t_mouse;

typedef struct	s_xpm_images
{
	pvoid	xpm;
	iarr	img;
}				t_xpm;

typedef struct	s_wolf3d_environment
{
	t_mlx		*mlx;
	t_isr		*isr;
	t_map		*map;
	t_rc		*rc;
	t_mouse		*mouse;
	t_xpm		*xpm;
}				t_env;

/*
**	t_tim using only for init MLX!
*/

typedef struct	s_temp_init_mlx
{
	int	bps;
	int	sl;
	int	end;
	int	w;
	int	h;
}				t_tim;

/*
**	t_helper using only for make texture rendering process
**		function avoid to norme.
*/

typedef struct	s_texture_render_helper
{
	int		d;
	int		curr_tex;
	int		curr_color_on_tex;
	point	pos_on_tex;
	float	where_is_hit;
}				t_texhelper;

typedef struct	s_floor_render_helper
{
	fpoint	fpos;
	fpoint	fcur;
	float	dist_wall;
	float	dist_player;
	float	current_dist;
	float	weight;
	point	ftex;
	int		check_board;
}				t_floorhelper;

bool			wolf_readnsave(string map_name, t_env *env);

bool			wolf_init(t_env *env);
void			wolf_init_rc_n_randomize_pos(t_env *env);

void			wolf_rendering_rc(t_env *env);
void			wolf_render_textured(t_env *env, point *p);
void			wolf_set_diststep(t_rc *rc);
void			wolf_check_hit(t_rc *rc, itab map);
void			wolf_set_draw_area(t_rc *rc);

int				wolf_killwindow(t_env *env);
int				wolf_key_hooks(int key, t_env *env);

int				wolf_mouse_release(int button, int x, int y, t_env *env);
int				wolf_mouse_press(int button, int x, int y, t_env *env);
int				wolf_mouse_moves(int x, int y, t_env *env);

void			wolf_rotate(t_rc *rc, float angle);
void			wolf_move(t_env *env, float dist);

void			wolf_free(t_env **env);
void			wolf_free_map(t_map **map);

#endif
