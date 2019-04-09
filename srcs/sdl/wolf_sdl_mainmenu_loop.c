/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_sdl_mainmenu_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:02:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 20:29:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	add_press_selector(t_env *env, bool *exit_)
{
	if (true == env->menu->is_selector_start)
	{
		Mix_VolumeMusic(env->sfx->bg_volume);
		wolf_sdl_rendering_loop(env);
	}
	else
		*exit_ = true;
}

static void	add_press_keys(t_env *env)
{
	if (SDLK_DOWN == env->sdl->event.key.keysym.sym
	&& false == env->menu->is_selector_start)
		Mix_PlayChannel(-1, env->sfx->selector_err, 0);
	else if (SDLK_UP == env->sdl->event.key.keysym.sym
		&& true == env->menu->is_selector_start)
		Mix_PlayChannel(-1, env->sfx->selector_err, 0);
	else if (SDLK_UP == env->sdl->event.key.keysym.sym)
	{
		env->menu->is_selector_start = true;
		Mix_PlayChannel(-1, env->sfx->selector, 0);
	}
	else if (SDLK_DOWN == env->sdl->event.key.keysym.sym)
	{
		env->menu->is_selector_start = false;
		Mix_PlayChannel(-1, env->sfx->selector, 0);
	}
	if (SDLK_q == env->sdl->event.key.keysym.sym)
		env->isr->is_play_music = !env->isr->is_play_music;
}

void		wolf_sdl_mainmenu_loop(t_env *env, bool *exit_)
{
	(SDL_QUIT == env->sdl->event.type) ? (*exit_ = true) : 0;
	if (SDL_KEYDOWN == env->sdl->event.type)
	{
		if (SDLK_ESCAPE == env->sdl->event.key.keysym.sym)
			*exit_ = true;
		else
			add_press_keys(env);
		if (SDLK_RETURN == env->sdl->event.key.keysym.sym)
			add_press_selector(env, exit_);
	}
}
