/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:38:46 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/07 21:52:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifdef __APPLE__
#  include "../frameworks/SDL2.framework/Headers/SDL.h"
#  include "../frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"
#  include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# endif

# ifdef __linux__
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_mixer.h>
#  include <SDL2/SDL_ttf.h>
# endif

# include "wolf3d_defines.h"
# include "../libft/includes/libft.h"

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
} __attribute__((packed))				t_colors;

typedef struct	s_point
{
	int32_t	y;
	int32_t	x;
}				t_p;

typedef struct	s_fpoint
{
	float	y;
	float	x;
}				t_fp;

typedef struct	s_fcolor
{
	float	r;
	float	g;
	float	b;
}				t_fcolor;

FCOLOR;
FPOINT;
POINT;
UIARR;
IARR;
ITAB;
UINT;

typedef struct	s_sdl
{
	SDL_Window	*win;
	SDL_Surface	*win_surface;
	SDL_Event	event;
	iarr		win_pixels;
	TTF_Font	*font;
	SDL_Surface	*font_surface;
}				t_sdl;

typedef struct	s_isrender
{
	bool	is_play_steps;
	bool	is_play_music;
	bool	is_boost_step;
	bool	is_textured;
	bool	is_render_minimap;
	bool	is_render_fog;
	bool	is_render_fps;
	bool	is_move_forward;
	bool	is_move_backward;
	bool	is_rotate_right;
	bool	is_rotate_left;
	bool	is_render_blur;
}				t_isr;

typedef struct	s_map
{
	itab	tab;
	itab	colors;
	point	size;
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
	int32_t	hline;
	int32_t	draw_start;
	int32_t	draw_end;
}				t_rc;

typedef struct	s_texture
{
	SDL_Surface	*surf;
	uiarr		pixels;
}				t_tex;

typedef struct	s_mouse
{
	bool	is_pressed_mouse;
	int32_t	last;
	int32_t	curr;
}				t_mouse;

typedef struct	s_time
{
	float	current;
	float	old;
	float	res;
}				t_time;

typedef struct	s_fps
{
	t_time	time;
	float	move;
	float	rot;
}				t_fps;

typedef struct	s_fog
{
	t_colors	color;
	Uint32		fog_color;
	float		fog_dist;
	uint8_t		freq;
}				t_fog;

typedef struct	s_menu
{
	t_tex		*bg;
	t_tex		*selector;
	bool		is_selector_start;
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
	Mix_Music	*ambient_bg;
	Mix_Chunk	*lstep;
	Mix_Chunk	*rstep;
	t_time		step_sfx_timeout;
	int16_t		bg_volume;
}				t_sfx;

typedef struct	s_walls
{
	t_tex	*data;
	point	*start;
	int32_t	in_row;
	int32_t	in_column;
	int32_t	max_textures;
}				t_walls;

typedef struct	s_wolf3d_environment
{
	t_sdl		*sdl;
	t_isr		*isr;
	t_map		*map;
	t_rc		*rc;
	t_tex		*floor_and_sky;
	t_walls		*walls;
	t_mouse		*mouse;
	t_fps		fps;
	t_fog		fog;
	t_menu		*menu;
	t_torch		*torch;
	t_sfx		*sfx;
	int32_t		bsize;
}				t_env;

FPTR_FLG;

/*
**		NORME HELP CODE START.
*/
typedef struct	s_texture_render_helper
{
	int32_t	d;
	int32_t	curr_tex;
	int32_t	currtcolor;
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

typedef struct	s_bhelp
{
	point	*p;
	iarr	src;
	float	*bmap;
	float	dimm;
	float	factor;
	point	size;
}				t_bhelp;
/*
**		NORME HELP CODE END.
*/
