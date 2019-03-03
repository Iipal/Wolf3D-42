/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_sdl_mainmenu_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:02:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/03 17:58:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_press_selector(t_env *env, bool *exit)
{
	if (env->menu->is_selector_start)
		wolf_sdl_rendering_loop(env);
	else
		*exit = true;
}

void		wolf_sdl_mainmenu_loop(t_env *env)
{
	bool	exit;

	exit = false;
	while (!exit)
	{
		while (SDL_PollEvent(&(env->sdl->event)) > 0)
		{
			(env->sdl->event.type == SDL_QUIT) ? (exit = true) : 0;
			if (env->sdl->event.type == SDL_KEYDOWN)
			{
				if (env->sdl->event.key.keysym.sym == SDLK_ESCAPE)
					exit = true;
				if (env->sdl->event.key.keysym.sym == SDLK_UP)
					env->menu->is_selector_start = true;
				if (env->sdl->event.key.keysym.sym == SDLK_DOWN)
					env->menu->is_selector_start = false;
				if (env->sdl->event.key.keysym.sym == 13)
					add_press_selector(env, &exit);
			}
		}
		wolf_rendering_mainmenu(env);
	}
	wolf_free(&env);
}
