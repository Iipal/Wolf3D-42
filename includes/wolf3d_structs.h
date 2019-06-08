/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:38:46 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/08 13:55:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_STRUCTS_H
# define WOLF3D_STRUCTS_H

# if defined __APPLE__ || defined __linux
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_ttf.h>
#  include <SDL2/SDL_mixer.h>
# else
#  error "Unsupported OS. Try to compile this on MacOS or Linux"
# endif

# include "wolf3d_defines.h"
# include "../libft/includes/libft.h"

/*
**	Uncommented cheats:
*/
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

struct	s_point
{
	int32_t	y;
	int32_t	x;
};

struct	s_fpoint
{
	float	y;
	float	x;
};

FPOINT;
POINT;
UIARR;
IARR;
ITAB;
UINT;

struct	s_sdl
{
	SDL_Window	*win;
	SDL_Surface	*win_surface;
	iarr		win_pixels;
	SDL_Event	event;
	TTF_Font	*font;
};

/*
**	(SDL_Window*)win: SDL2 window.
**	(SDL_Surface*)win_surface: SDL_GetWindowSurface(.win);
**	(iarr)win_pixels: shortcut for .win_surface->pixels;
**	(SDL_Event)event: SDL2 events structs for SDL_PollEvent(&.event);
**	(TTF_Font*)font: SDL2 font. (used only for FPS\ms info rendering)
*/
typedef struct s_sdl	t_sdl;

struct	s_isrender
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
	bool	is_use_mouse;
	bool	is_no_main_menu;
	bool	is_world_sides_textures;
};

/*
**	All variables is bool(on/off options):
**
**	is_play_steps: Steps sound .(default: on)
**	is_play_music: Background music. (default: on)
**	is_boost_step: RUN FOREST RUN. (default: off)
**	is_textures: Texture rendering. (default: on)
**	is_render_minimap: Minimap rendering. (default: on)
**	is_render_fog: Fog effect. (default: on)
**	is_render_fps: FPS\ms debug info. (default: off)
**	is_move_forward: Player camera movement forward. (default: off)
**	is_move_backward: Player camera movement backward. (default: off)
**	is_rotate_left: Player camera rotate left. (default: off)
**	is_rotate_right: Player camera rotate right. (default: off)
**	is_render_blur: Bluring post-effect. (default: off)
*/
typedef struct s_isrender	t_isr;

struct	s_map
{
	int8_t	**tab;
	itab	colors;
	point	size;
};

/*
**	(int8_t**)tab: Values from map(0-9), which texture use for each wall on map
**	(itab)colors: Map colors based on .itab. (used for non textures render)
**	(point)size: Map size.
*/
typedef struct s_map	t_map;

struct	s_ray_caster
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
};

/*
**	All variables used for RayCasting render.
**	(more info here: https://lodev.org/cgtutor/raycasting.html)
*/
typedef struct s_ray_caster	t_rc;

struct	s_texture
{
	SDL_Surface	*surf;
	uiarr		pixels;
};

/*
**	(SDL_Surface*)surf: Texture surface.
**	(uiarr)pixels: shortcut for .surf->pixels. (cast from void* to uiarr)
*/
typedef struct s_texture	t_tex;

struct	s_mouse
{
	bool	is_pressed_mouse;
	int32_t	last;
	int32_t	curr;
};

/*
**	(bool)is_pressed_mouse: Left mouse button press trigger.
**	(int32_t)last: Latest mouse position.
**	(int32_t)curr: Current mouse postion.
*/
typedef struct s_mouse	t_mouse;

struct	s_time
{
	float	old;
	float	current;
	float	res;
};

/*
**	(float)old: Previous time. | = .current;
**	(float)current: Current time. | SDL_GetTicks();
**	(float)res: Diff current and old time in ms. | (.current - .old) / 1000;
*/
typedef struct s_time	t_time;

struct	s_fps
{
	t_time	time;
	float	move;
	float	rot;
};

/*
**	(t_time)time: 1 frame rendering time.
**	(float)move: FPS based movement value. | .time.res * MOVE_INC;
**	(float)rot: FPS based rotata value. | .time.res * ROT_INC;
*/
typedef struct s_fps	t_fps;

struct	s_fog
{
	t_colors	color;
	Uint32		fog_color;
	float		fog_dist;
	uint8_t		freq;
};

/*
**	(t_colors)color: Current fog color number.
**	(Uint32)fog_color: Current fog color based on .color
**	(float)fog_dist: Current max visible distance in fog.
**	(uint8_t)freq: Current .fog_dist frequency value.
*/
typedef struct s_fog	t_fog;

struct	s_menu
{
	t_tex		*bg;
	t_tex		*selector;
	bool		is_selector_start;
};

/*
**	(t_tex)selector: Menu selector texture.
**	(t_tex)bg: Menu background texture.
**	(bool)is_selector_start: Trigger for menu option selection.
**		If value is true in menu selector will draw in below of "START" option
**			and above "EXIT". If press Enter and value is true game will start.
*/
typedef struct s_menu	t_menu;

struct	s_torch
{
	float	delta;
	t_tex	*tex;
};

/*
**	(t_time)time: Delta time for refreshing torch frame
**		every REFRESH_TORCH_FOG_FREQ time.
**	(t_tex*)tex: Torch textures.(pointer to t_tex one-dimensional array)
*/
typedef struct s_torch	t_torch;

struct	s_sfx
{
	Mix_Chunk	*start;
	Mix_Chunk	*selector;
	Mix_Chunk	*selector_err;
	Mix_Music	*ambient_bg;
	Mix_Chunk	*lstep;
	Mix_Chunk	*rstep;
	t_time		step_sfx_timeout;
	int16_t		bg_volume;
};

/*
**	(Mix_Music*)ambient_bg: Background music.
**	(int16_t)bg_volume:  ambient_bg volume. In menu divided by BG_VOL_MUTE.
**
**	(Mix_Chunk* all fields above)
**	Played only in menu:
**	 start: Only when window successfull opened.
**	 selector: When t_menu.is_selector_start value is changed.
**	 selector_err: When t_menu.is_selector_start value isnt changed
**	  but you trying to change it.
**	  (When selector on "EXIT" and you try press down arrow).
**
**	Played only in game:
**	 lstep: Left step sound.
**	 rstep: Right step sound.(Not 5.1 effect, just diff sound)
**
**	(t_time)step_sfx_timeout: Delta time for pause playing step sounds.
**	 If t_isr.is_boost_step is true pause is REFRESH_RUN_SFX_FREQ,
**	 else REFRESH_STEP_SFX_FREQ.
*/
typedef struct s_sfx	t_sfx;

struct	s_walls
{
	t_tex	*data;
	point	*start;
	int32_t	in_row;
	int32_t	in_column;
	int32_t	max_textures;
};

/*
**	(t_tex)data: Walls texture.
**	(point)start: Start position on texture map each walls texture.
**	(int32_t)in_row: textures count in 1 row in texture map.
**	(int32_t)in_column: textures count in 1 cloumn in texture map.
**	(int32_t)max_textures: All textures count in texture map.
*/
typedef struct s_walls	t_walls;

struct	s_wolf3d_environment
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
};

/*
**	(t_sdl*)sdl: All sdl stuff what needed to work with SDL2 framework.
**	(t_isr*)isr: Full bool struct with flags for e\disable all binding features.
**	(t_map*)map: Map readed from file.
**	(t_rc*)rc: All RayCasting data.
**	(t_tex*)floor_and_sky: Texture map with floor and sky textures.
**	(t_walls*)walls: Texture map with all walls textures.
**	(t_mouse*)mouse: Save mouse position & press trigger.
**	(t_fps)fps: FPS, delta time & FPS based movements.
**	(t_fog)fog: Save fog color, disrance & frequence.
**	(t_menu*)menu: Menu background, option selector & press trigger.
**	(t_torch*)torch: Texture for rendering torch with itself delta time.
**	(t_sfx*)sfx: Chunks, music. (sfx - Sound Effects)
**	(int32_t)bsize: Blur amount.
**	 (More about blur in srcs/blur/wolf_blur.c
**	  & https://lodev.org/cgtutor/filtering.html#Blur)
*/
typedef struct s_wolf3d_environment	t_env;

/*
**	NORME HELP CODE START.
*/
struct	s_texture_render_helper
{
	int32_t	d;
	int32_t	curr_tex;
	int32_t	currtcolor;
	point	pos_on_tex;
	float	where_is_hit;
};

/*
**	Help for t_rc. (https://lodev.org/cgtutor/raycasting.html)
*/
typedef struct s_texture_render_helper	t_texhelp;

struct	s_floor_render_helper
{
	fpoint	fpos;
	fpoint	fcur;
	float	currd;
	float	weight;
	point	ftex;
};

/*
**	Help for t_rc. (https://lodev.org/cgtutor/raycasting.html)
*/
typedef struct s_floor_render_helper	t_floorhelper;

struct	s_fcolor
{
	float	r;
	float	g;
	float	b;
};

FCOLOR;

struct	s_bhelp
{
	point	*p;
	iarr	src;
	float	*bmap;
	float	dimm;
	float	factor;
	point	size;
};

/*
**	Help for blur(srcs/blur/wolf_blur.c
**	 & https://lodev.org/cgtutor/filtering.html#Blur)
*/
typedef struct s_bhelp	t_bhelp;

/*
**	NORME HELP CODE END.
*/

#endif
