/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_sdl_rendering_loop_key_press.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:26:54 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/07 00:59:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_rendering_loop_keys_press(t_env *env, bool *exit)
{
	IFDO(SEKEY == SDLK_ESCAPE, *exit = true);
	IFDO(SEKEY == SDLK_w, env->isr->is_move_forward = 1);
	IFDO(SEKEY == SDLK_a, env->isr->is_rotate_left = 1);
	IFDO(SEKEY == SDLK_s, env->isr->is_move_backward = 1);
	IFDO(SEKEY == SDLK_d, env->isr->is_rotate_right = true);
	IFDO(SEKEY == SDLK_f, env->isr->is_render_fog = !env->isr->is_render_fog);
	IFDO(SEKEY == SDLK_r, env->isr->is_render_fps = !env->isr->is_render_fps);
	IFDO(SEKEY == SDLK_m,
		env->isr->is_render_minimap = !env->isr->is_render_minimap);
	IFDO(SEKEY == SDLK_LSHIFT, env->isr->is_boost_step = true);
	IFDO(SEKEY == SDLK_t, env->isr->is_textured = !env->isr->is_textured);
	IFDO(SEKEY == SDLK_c,
		env->fog.fog_color = wolf_fog_change(&(env->fog.color)));
	IFDO(SEKEY == SDLK_h,
		env->isr->is_render_blur = !env->isr->is_render_blur);
	IFDO(SEKEY == SDLK_y,
		IFDO(!(env->bsize + BLUR_INC > BLUR_MAX), env->bsize += BLUR_INC));
	IFDO(SEKEY == SDLK_n,
		IFDO(!(env->bsize - BLUR_INC < BLUR_MIN), env->bsize -= BLUR_INC));
}

void	wolf_rendering_loop_keys_release(t_env *env)
{
	IFDO(SEKEY == SDLK_w, env->isr->is_move_forward = false);
	IFDO(SEKEY == SDLK_a, env->isr->is_rotate_left = false);
	IFDO(SEKEY == SDLK_s, env->isr->is_move_backward = false);
	IFDO(SEKEY == SDLK_d, env->isr->is_rotate_right = false);
	IFDO(SEKEY == SDLK_LSHIFT, env->isr->is_boost_step = false);
}

void	wolf_rendering_loop_keys_sfx_press(t_env *env)
{
	IFDO(SEKEY == SDLK_q, env->isr->is_play_music = !env->isr->is_play_music);
	IFDO(SEKEY == SDLK_EQUALS,
		IFDO(!(env->sfx->bg_volume + BG_VOL_INC > BG_VOL_MAX),
			env->sfx->bg_volume += BG_VOL_INC));
	IFDO(SEKEY == SDLK_MINUS,
		IFDO(!(env->sfx->bg_volume - BG_VOL_INC < BG_VOL_MIN),
			env->sfx->bg_volume -= BG_VOL_INC));
	IFDO(SEKEY == SDLK_z, env->isr->is_play_steps = !env->isr->is_play_steps);
}
