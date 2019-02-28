/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_sdl_mainmenu_events.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:44:27 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/28 11:49:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			wolf_start_game(t_env *env)
{
	wolf_sdl_rendering_loop(env);
}

void			wolf_options(t_env *env)
{
	if (env)
	{
	}
	_MSGN("Options menu in development");
}

void			wolf_exit(t_env *env)
{
	wolf_free(&env);
	SDL_Quit();
	exit(EXIT_SUCCESS);
}

void			wolf_press_selector(t_env *env)
{
	const fn_selector	fn_ptrs[] = {
		&wolf_start_game, &wolf_options, &wolf_exit
	};

	fn_ptrs[env->menu->selector_shift](env);
}
