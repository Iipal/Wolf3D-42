/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_sdl_mainmenu_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:02:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/28 11:36:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	add_move_selector(short *current_selector_shift, short move)
{
	*current_selector_shift += move;
	if (*current_selector_shift < 0)
		*current_selector_shift = 0;
	if (*current_selector_shift > 2)
		*current_selector_shift = 2;
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
					add_move_selector(&(env->menu->selector_shift), -1);
				if (env->sdl->event.key.keysym.sym == SDLK_DOWN)
					add_move_selector(&(env->menu->selector_shift), 1);
				if (env->sdl->event.key.keysym.sym == 13)
					wolf_press_selector(env);
			}
		}
		wolf_rendering_mainmenu(env);
	}
	SDL_DestroyWindow(env->sdl->win);
	wolf_free(&env);
	SDL_Quit();
}
