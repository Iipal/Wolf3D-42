/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:30:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/18 11:09:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# ifdef __APPLE__
#  define WIN_X		2000
#  define WIN_Y		1000
# endif

# ifdef __linux__
#  define WIN_X		1000
#  define WIN_Y		500
# endif

# include "wolf3d_defines.h"
# include "wolf3d_errno.h"
# include "../libft/includes/libft.h"
# include <SDL2/SDL.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

enum	e_bool {false, true} __attribute__((packed));

typedef enum	e_colors
{
	white,
	red,
	orange,
	lime,
	aqua,
	purple,
	mint,
	dark_blue,
	dark,
	max_colors
}	__attribute__((packed))	t_clrs;

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

typedef struct	s_sdl
{
	SDL_Window	*win;
	SDL_Surface	*win_surface;
	SDL_Event	event;
	iarr		win_pixels;
}				t_sdl;


typedef struct	s_isrender
{
	bool	is_render;
	bool	is_boost_step;
	bool	is_textured;
	bool	is_draw_minimap;
	bool	is_render_fog;
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
	fpoint	ddist;
	double	pwd;
	point	step;
	bool	is_hit;
	bool	is_side;
	int		hline;
	int		draw_start;
	int		draw_end;
	t_clrs	clr;
	Uint32	fog_color;
	double	fog_dist;
}				t_rc;

typedef struct	s_textures
{
	SDL_Surface	*surf;
	iarr		pixels;
}				t_tex;

typedef struct	s_wolf3d_environment
{
	t_sdl		*sdl;
	t_isr		*isr;
	t_map		*map;
	t_rc		*rc;
	t_tex		*textures;
}				t_env;

/*
**	t_helper using only for make texture rendering process
**		function avoid to norme.
*/

typedef struct	s_texture_render_helper
{
	int		d;
	int		curr_tex;
	int		currtcolor;
	point	pos_on_tex;
	float	where_is_hit;
}				t_texhelper;

typedef struct	s_floor_render_helper
{
	fpoint	fpos;
	fpoint	fcur;
	float	currd;
	float	weight;
	point	ftex;
}				t_floorhelper;

bool			wolf_readnsave(string map_name, t_env *env);

SDL_Surface		*wolf_optimize_surf_load(string bmp_path, const SDL_PixelFormat *format);

bool			wolf_init(t_env *env);
void			wolf_init_rc_n_randomize_pos(t_env *env);

void			wolf_draw_minimap(t_env *env);
Uint32			wolf_fog(double dist, Uint32 src_color, Uint32 fog_color, double fog_dist);
Uint32			wolf_fog_change(t_clrs *c);

void			wolf_sdl_loop(t_env *env);

void			wolf_rendering_rc(t_env *env);

void			wolf_render_textured(t_env *env, point *p);
void			wolf_render_colored(t_env *env, point *p);
void			wolf_fill_floor_if_colored_rc(t_sdl *sdl);

void			wolf_set_diststep(t_rc *rc);
void			wolf_check_hit(t_rc *rc, itab map);
void			wolf_dist_to_wall(t_rc *rc);

bool			wolf_is_tile(t_map *map, fpoint pos);

void			wolf_rotate(t_rc *rc, float angle);
void			wolf_move(t_env *env, float dist);

void			wolf_free(t_env **env);
void			wolf_free_map(t_map **map);

#endif
