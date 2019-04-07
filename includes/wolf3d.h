/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:30:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/08 02:39:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "wolf3d_structs.h"
# include "wolf3d_errno.h"
# include <math.h>

/*
**	Flags parsing:
*/
FPTR_FLG;

bool		wolf_fparser(t_env *env, strtab av, int32_t ac);
void		wolf_fhelp(t_env *env, strtab av, int32_t ac);
void		wolf_fnoborder(t_env *env, strtab av, int32_t ac);

/*
**	Reading and save map:
*/
bool		wolf_readnsave(string map_name, t_env *env);

/*
**	Initialize & allocating memory for t_env and all game data:
*/
bool		wolf_init(t_env *env);
bool		wolf_init_textures(t_env *env);
void		wolf_setup_rc(t_env *env);

/*
**	Main menu rendering and sdl event loops:
*/
void		wolf_rendering_mainmenu(t_env *env);
void		wolf_sdl_mainmenu_loop(t_env *env, bool *exit_);

/*
**	Game rendering and sdl event loops:
*/
void		wolf_rendering(t_env *env);

void		wolf_raycaster(t_env *env);
void		wolf_render_colored(t_env *env, point *p);
void		wolf_render_textured(t_env *env, point *p);
void		wolf_render_textured_draw_line(t_env *env, point *p, t_texhelp *h);

void		wolf_sdl_rendering_loop(t_env *env);
void		wolf_rendering_loop_keys_press(t_env *env, bool *exit);
void		wolf_rendering_loop_keys_release(t_env *env);
void		wolf_rendering_loop_keys_sfx_press(t_env *env);

void		wolf_rotate(t_rc *rc, float angle);
void		wolf_move(t_env *env, float dist);

void		wolf_fps(t_fps *fps);

bool		wolf_is_tile(t_map *map, fpoint pos);

/*
**	Bonuses:
*/
void		wolf_rendering_fps_counter(t_env *env);
void		wolf_rendering_minimap(t_env *env);
void		wolf_rendering_torch(t_env *env);

Uint32		wolf_fog(float dist_to_obj, Uint32 src_color, t_fog *fog);
Uint32		wolf_fog_change(t_colors *c);
float		wolf_fog_freq(uint8_t *freq, t_time *time);

void		wolf_blur(point size, iarr src, float value, float dimmed);

void		wolf_playing_steps(t_sfx *sfx, bool is_boost);

/*
**	Free allocated memory:
*/
void		wolf_free(t_env **env);
void		wolf_free_map(t_map **map);

/*
**	SDL optimizing functions for correct load Surfaces and Fonts:
*/
SDL_Surface	*wolf_optimize_surf_load(string bmp_path,
						const SDL_PixelFormat *format);
SDL_Surface	*wolf_optimize_font_load(string text, SDL_Color text_color,
								TTF_Font *font, SDL_PixelFormat *format);

#endif
