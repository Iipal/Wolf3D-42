/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_sdl_rendering_loop_key_press_events.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:26:54 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/02 20:20:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wofl_rendering_loop_keys_press(t_env *env, bool *exit)
{
	(SEKEY == SDLK_ESCAPE) ? (*exit = true) : 0;
	if (SEKEY == SDLK_w || SEKEY == SDLK_UP)
		env->isr->is_move_forward = true;
	if (SEKEY == SDLK_a || SEKEY == SDLK_LEFT)
		env->isr->is_rotate_left = true;
	if (SEKEY == SDLK_s || SEKEY == SDLK_DOWN)
		env->isr->is_move_backward = true;
	if (SEKEY == SDLK_d || SEKEY == SDLK_RIGHT)
		env->isr->is_rotate_right = true;
	if (SEKEY == SDLK_f)
		env->isr->is_render_fog = !env->isr->is_render_fog;
	if (SEKEY == SDLK_r)
		env->isr->is_render_fps = !env->isr->is_render_fps;
	if (SEKEY == SDLK_m)
		env->isr->is_render_minimap = !env->isr->is_render_minimap;
	(SEKEY == SDLK_LSHIFT) ? (env->isr->is_boost_step = true) : 0;
	(SEKEY == SDLK_t) ? (env->isr->is_textured = !env->isr->is_textured) : 0;
	if (SEKEY == SDLK_c)
		env->fog.fog_color = wolf_fog_change(&(env->fog.color));
	if (SEKEY == SDLK_h)
		env->isr->is_render_blur = !env->isr->is_render_blur;
	if (SEKEY == SDLK_y)
		(env->bsize + BLUR_INC > BLUR_MAX) ? (env->bsize = BLUR_MAX)
		: (env->bsize += BLUR_INC);
	if (SEKEY == SDLK_n)
		(env->bsize - BLUR_INC < BLUR_MIN) ? (env->bsize = BLUR_MIN)
		: (env->bsize -= BLUR_INC);
}

void	wofl_rendering_loop_keys_sfx_press(t_env *env)
{
	if (SEKEY == SDLK_q)
		env->isr->is_play_music = !env->isr->is_play_music;
	if (SEKEY == SDLK_EQUALS)
		(env->sfx->bg_volume + BG_VOL_INC >= BG_VOL_MAX)
			? (env->sfx->bg_volume = BG_VOL_MAX)
			: (env->sfx->bg_volume += BG_VOL_INC);
	if (SEKEY == SDLK_MINUS)
		(env->sfx->bg_volume - BG_VOL_INC <= BG_VOL_MIN)
			? (env->sfx->bg_volume = BG_VOL_MIN)
			: (env->sfx->bg_volume -= BG_VOL_INC);
	if (SEKEY == SDLK_z)
		env->isr->is_play_steps = !env->isr->is_play_steps;
}

void	wofl_rendering_loop_keys_release(t_env *env)
{
	if (SEKEY == SDLK_w || SEKEY == SDLK_UP)
		env->isr->is_move_forward = false;
	if (SEKEY == SDLK_a || SEKEY == SDLK_LEFT)
		env->isr->is_rotate_left = false;
	if (SEKEY == SDLK_s || SEKEY == SDLK_DOWN)
		env->isr->is_move_backward = false;
	if (SEKEY == SDLK_d || SEKEY == SDLK_RIGHT)
		env->isr->is_rotate_right = false;
	(SEKEY == SDLK_LSHIFT) ? (env->isr->is_boost_step = false) : 0;
}
