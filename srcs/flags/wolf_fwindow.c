/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_fwindow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:24:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 16:44:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_fnoborder(t_env *env, strtab av, int32_t ac)
{
	(void)ac;
	(void)av;
	FREE(env->sdl->win, SDL_DestroyWindow);
	env->sdl->win = SDL_CreateWindow(WOLF_TITLE, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y,
		SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
	NOTIS2(SDL_GetError(), env->sdl->win, wolf_free(&env), exit(EXIT_FAILURE));
	env->sdl->win_surface = SDL_GetWindowSurface(env->sdl->win);
	env->sdl->win_pixels = env->sdl->win_surface->pixels;
}

void	wolf_fmouse(t_env *env, strtab av, int32_t ac)
{
	(void)av;
	(void)ac;
	env->isr->is_use_mouse = true;
	SDL_ShowCursor(SDL_FALSE);
	SDL_SetRelativeMouseMode(SDL_TRUE);
}
