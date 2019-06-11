/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_sdl_rendering_loop.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 22:59:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/11 22:17:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	add_mouse_moves(t_env *env)
{
	SDL_GetMouseState(&(env->sdl->event.motion.x), &(env->sdl->event.motion.y));
	if (SDL_MOUSEBUTTONDOWN == env->sdl->event.type)
		env->mouse->is_pressed_mouse = true;
	if (SDL_MOUSEBUTTONUP == env->sdl->event.type)
		env->mouse->is_pressed_mouse = false;
	env->mouse->last = env->mouse->curr;
	env->mouse->curr = env->sdl->event.motion.x;
	if (env->mouse->is_pressed_mouse || env->isr->is_use_mouse)
		wolf_rotate(env->rc, -(env->sdl->event.motion.x - env->mouse->last)
							* ROT_MOUSE_INC);
}

static void	add_loop_isr(t_env *env)
{
	if ((env->isr->is_move_backward
		|| env->isr->is_move_forward)
		&& env->isr->is_play_steps)
		wolf_playing_steps(env->sfx, env->isr->is_boost_step);
	if (env->isr->is_move_forward)
		wolf_move(env, (env->isr->is_boost_step)
			? (MOVE_BOOST * env->fps.move) : env->fps.move);
	if (env->isr->is_rotate_left)
		wolf_rotate(env->rc, RAD((env->isr->is_boost_step)
			? (ROT_BOOST * env->fps.rot) : env->fps.rot));
	if (env->isr->is_move_backward)
		wolf_move(env, (env->isr->is_boost_step)
			? (MOVE_BOOST * -env->fps.move) : -env->fps.move);
	if (env->isr->is_rotate_right)
		wolf_rotate(env->rc, RAD((env->isr->is_boost_step)
			? (ROT_BOOST * -env->fps.rot) : -env->fps.rot));
	Mix_VolumeMusic(env->sfx->bg_volume);
	if (env->isr->is_play_music)
		Mix_ResumeMusic();
	else
		Mix_PauseMusic();
}

void		wolf_sdl_rendering_loop(t_env *env)
{
	bool	quit;

	quit = false;
	while (!quit)
	{
		while (0 < SDL_PollEvent(&env->sdl->event))
		{
			IFDO(SDL_QUIT == env->sdl->event.type, quit = true);
			if (SDL_KEYDOWN == env->sdl->event.type)
			{
				wolf_rendering_loop_keys_press(env, &quit);
				wolf_rendering_loop_keys_sfx_press(env);
			}
			if (SDL_KEYUP == env->sdl->event.type)
				wolf_rendering_loop_keys_release(env);
			add_mouse_moves(env);
		}
		add_loop_isr(env);
		wolf_rendering(env);
	}
	IFDO(env->isr->is_play_music,
		Mix_VolumeMusic(env->sfx->bg_volume / BG_VOL_MUTE));
}
