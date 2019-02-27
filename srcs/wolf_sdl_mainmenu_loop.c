/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_sdl_mainmenu_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:02:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/27 14:33:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		wolf_sdl_mainmenu_loop(t_env *env)
{
	bool	exit;

	exit = false;
	while (!exit)
	{
		while (SDL_PollEvent(&SEVENT) > 0)
		{
			(SETYPE == SDL_QUIT) ? (exit = true) : 0;
			if (SETYPE == SDL_KEYDOWN)
				(SEKEY == SDLK_ESCAPE) ? (exit = true) : 0;
		}
		wolf_rendering_mainmenu(env);
	}
	SDL_DestroyWindow(SWIN);
	wolf_free(&env);
}
