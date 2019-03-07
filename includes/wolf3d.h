/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:30:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/07 11:28:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# ifdef __APPLE__
#  include "../frameworks/SDL2.framework/Headers/SDL.h"
#  include "../frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"
# endif

# ifdef __linux__
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_mixer.h>
# endif

# include "wolf3d_defines.h"
# include "wolf3d_errno.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <math.h>

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
} __attribute__((packed))				t_clrs;

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
_UIARR;
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
	bool	is_play_steps;
	bool	is_play_music;
	bool	is_boost_step;
	bool	is_textured;
	bool	is_draw_minimap;
	bool	is_render_fog;
	bool	is_move_forward;
	bool	is_move_backward;
	bool	is_rotate_right;
	bool	is_rotate_left;
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
	float	xcamera;
	fpoint	raydir;
	point	map;
	fpoint	side_dist;
	fpoint	ddist;
	float	pwd;
	point	step;
	bool	is_hit;
	bool	is_side;
	int		hline;
	int		draw_start;
	int		draw_end;
}				t_rc;

typedef struct	s_textures
{
	SDL_Surface	*surf;
	uiarr		pixels;
}				t_tex;

typedef struct	s_mouse
{
	bool	is_pressed_mouse;
	int		last;
	int		curr;
}				t_mouse;

typedef struct	s_time
{
	float	current_time;
	float	old_time;
	float	res_time;
}				t_time;

typedef struct	s_fps
{
	t_time	time;
	float	move;
	float	rot;
}				t_fps;

typedef struct	s_fog
{
	t_clrs	clr;
	Uint32	fog_color;
	float	fog_dist;
	int		freq;
}				t_fog;

typedef struct	s_menu
{
	t_tex	*bg;
	t_tex	*selector;
	bool	is_selector_start;
}				t_menu;

typedef struct	s_torch
{
	t_time	time;
	t_tex	*tex;
}				t_torch;

typedef struct	s_sfx
{
	Mix_Chunk	*start;
	Mix_Chunk	*selector;
	Mix_Chunk	*selector_err;
	Mix_Chunk	*exit;
	Mix_Music	*ambient_bg;
	Mix_Chunk	*lstep;
	Mix_Chunk	*rstep;
	t_time		step_sfx_timeout;
	short		bg_volume;
}				t_sfx;

typedef struct	s_wolf3d_environment
{
	t_sdl		*sdl;
	t_isr		*isr;
	t_map		*map;
	t_rc		*rc;
	t_tex		*textures;
	t_mouse		*mouse;
	t_fps		fps;
	t_fog		fog;
	t_menu		*menu;
	t_torch		*torch;
	t_sfx		*sfx;
}				t_env;

/*
**		NORME HELP CODE START.
**
**	t_texhelper && t_floorhelper using only for
**		make texture rendering process function avoid to norme.
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
/*
**		NORME HELP CODE END.
*/

bool			wolf_readnsave(string map_name, t_env *env);

SDL_Surface		*wolf_optimize_surf_load(string bmp_path,
								const SDL_PixelFormat *format);

bool			wolf_init(t_env *env);
void			wolf_setup_rc(t_env *env);

void			wolf_draw_minimap(t_env *env);
Uint32			wolf_fog(float dist, Uint32 src_color, t_fog *fog);
Uint32			wolf_fog_change(t_clrs *c);

void			wofl_rendering_loop_keys_press(t_env *env, bool *exit);
void			wofl_rendering_loop_keys_sfx_press(t_env *env);

void			wolf_sdl_rendering_loop(t_env *env);
void			wolf_sdl_mainmenu_loop(t_env *env);

void			wolf_rendering_rc(t_env *env);
void			wolf_rendering_mainmenu(t_env *env);

void			wolf_render_textured_help(t_env *env, point *p, t_texhelper *h);
void			wolf_render_textured(t_env *env, point *p);
void			wolf_render_colored(t_env *env, point *p);
void			wolf_fill_floor_if_colored_rc(t_sdl *sdl);

void			wolf_set_diststep(t_rc *rc);
void			wolf_check_hit(t_rc *rc, itab map);
void			wolf_dist_to_wall(t_rc *rc);

bool			wolf_is_tile(t_map *map, fpoint pos);

void			wolf_rotate(t_rc *rc, float angle);
void			wolf_move(t_env *env, float dist);

void			wolf_playing_steps(t_sfx *sfx, bool is_boost);

void			wolf_press_selector(t_env *env);

void			wolf_free(t_env **env);
void			wolf_free_map(t_map **map);

#endif
