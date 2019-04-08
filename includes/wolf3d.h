/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:30:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/08 17:00:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

/**
** \file
*/
# include "wolf3d_structs.h"
# include "wolf3d_errno.h"
# include <math.h>

/*
**	--------------
**	Flags parsing:
**	--------------
*/
FPTR_FLG;

/*
**	Function what will parse all flags.
*/
bool		wolf_fparser(t_env *env, strtab av, int32_t ac);

/*
**	Function what will processing flag '-h'
*/
void		wolf_fhelp(t_env *env, strtab av, int32_t ac);

/*
**	Function what will processing flag '-no-border'
*/
void		wolf_fnoborder(t_env *env, strtab av, int32_t ac);

/*
**	--------------------
**	Initialize all data:
**	--------------------
*/

/*
**	Reading and save map.
*/
bool		wolf_readnsave(string map_name, t_env *env);

/*
**	Initialize & allocating memory for t_env and all game data:
*/
bool		wolf_init(t_env *env);

/*
**	Initialize textures and texture maps.
*/
bool		wolf_init_textures(t_env *env);

/*
**	Setup RayCasting default settings.
*/
void		wolf_setup_rc(t_env *env);

/*
**	----------
**	Main menu:
**	----------
*/

/*
**	Main menu rendering.
*/
void		wolf_rendering_mainmenu(t_env *env);

/*
** Main menu SDL2 events & rendering loop.
*/
void		wolf_sdl_mainmenu_loop(t_env *env, bool *exit_);

/*
**	---------------------
**	Game & ingame events:
**	---------------------
*/

/*
**	Function what render each frame.
*/
void		wolf_rendering(t_env *env);

/*
**	RayCasting engine processing.
*/
void		wolf_raycaster(t_env *env);

/*
**	Render each Y line from wolf_raycaster() in colored mode.
*/
void		wolf_render_colored(t_env *env, point *p);

/*
**	Render each Y line from wolf_raycaster() in textured mode.
*/
void		wolf_render_textured(t_env *env, point *p);

/*
**	Help rendering for wolf_render_textured(). (School-42 Norme)
*/
void		wolf_render_textured_draw_line(t_env *env, point *p, t_texhelp *h);

/*
**	SDL2 in-game events & rendering loop.
*/
void		wolf_sdl_rendering_loop(t_env *env);

/*
**	Catch key presses.
*/
void		wolf_rendering_loop_keys_press(t_env *env, bool *exit);

/*
**	Catch key realeses.
*/
void		wolf_rendering_loop_keys_release(t_env *env);

/*
**	Catch key presse what is responsible for sound effects.
*/
void		wolf_rendering_loop_keys_sfx_press(t_env *env);

/*
**	Rotate player camera.
*/
void		wolf_rotate(t_rc *rc, float angle);

/*
**	 Player camera movements.
*/
void		wolf_move(t_env *env, float dist);

/*
**	FPS counter & evauluate comfortable for play movement and rotate values.
**	 (to move and camera rotate a constant speed
**	  no matter how long the calculation of the frames takes),
*/
void		wolf_fps(t_fps *fps);

/*
**	For checking is player\RayCasting ray on valid peace of map.
*/
bool		wolf_is_tile(t_map *map, fpoint pos);

/*
**	--------
**	Bonuses:
**	--------
*/

/*
**	Render FPS\ms info.
*/
void		wolf_rendering_fps_counter(t_env *env);

/*
**	Render minimap.
*/
void		wolf_rendering_minimap(t_env *env);

/*
**	Render torch.
*/
void		wolf_rendering_torch(t_env *env);

/*
**	Render fog.
*/
Uint32		wolf_fog(float dist_to_obj, Uint32 src_color, t_fog *fog);

/*
**	Change fog color.
*/
Uint32		wolf_fog_change(t_colors *c);

/*
**	Change for_dist & torch frame.
*/
float		wolf_fog_freq(uint8_t *freq, t_time *time);

/*
**	Render blur.
*/
void		wolf_blur(point size, iarr src, float value, float dimmed);

/*
**	Play steps sound effects.
*/
void		wolf_playing_steps(t_sfx *sfx, bool is_boost);

/*
**	----------------------
**	Free allocated memory:
**	----------------------
*/

/*
**	Free all alocated memory.
*/
void		wolf_free(t_env **env);

/*
**	Free t_map.
*/
void		wolf_free_map(t_map **map);

/*
**	-------------------------------------------------------------
**	SDL optimizing functions for correct load Surfaces and Fonts:
**	-------------------------------------------------------------
*/

/*
**	Optimize SDL_Surface loading.
*/
SDL_Surface	*wolf_optimize_surf_load(string bmp_path,
						const SDL_PixelFormat *format);

/*
**	Optimize font loading in SDL_Surface.
*/
SDL_Surface	*wolf_optimize_font_load(string text, SDL_Color text_color,
								TTF_Font *font, SDL_PixelFormat *format);

#endif
