/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_sdl_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 22:59:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/17 09:53:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_is_draw_bonus(t_env *env)
{
	if (SEKEY == SDLK_m && (ISRR = true))
		ISRMM = !ISRMM;
	if (SEKEY == SDLK_LSHIFT && (ISRR = true))
		ISRB = !ISRB;
	if (SEKEY == SDLK_t && (ISRR = true))
		ISRT = !ISRT;
	if (SEKEY == SDLK_c && (ISRR = true))
		RC->fog_color = wolf_fog_change(&(RC->clr));
}

static void	add_actions(t_env *env)
{
	if ((SEKEY == SDLK_w || SEKEY == SDLK_UP) && (ISRR = true))
		wolf_move(env, ISRB ? (MOVE_BOOST * MOVE_INC) : MOVE_INC);
	if ((SEKEY == SDLK_a || SEKEY == SDLK_LEFT) && (ISRR = true))
		wolf_rotate(RC, _RAD(ISRB ? (ROT_BOOST * ROT_INC) : ROT_INC));
	if ((SEKEY == SDLK_s || SEKEY == SDLK_DOWN) && (ISRR = true))
		wolf_move(env, ISRB ? (MOVE_BOOST * -MOVE_INC) : -MOVE_INC);
	if ((SEKEY == SDLK_d || SEKEY == SDLK_RIGHT) && (ISRR = true))
		wolf_rotate(RC, _RAD(ISRB ? (ROT_BOOST * -ROT_INC) : -ROT_INC));
}

void		wolf_sdl_loop(t_env *env)
{
	bool	exit;

	exit = false;
	while (!exit)
	{
		while (SDL_PollEvent(&SEVENT) > 0)
		{
			ISRR = false;
			if (SETYPE == SDL_QUIT)
				exit = true;
			if (SETYPE == SDL_KEYDOWN)
			{
				if (SEKEY == SDLK_ESCAPE)
					exit = true;
				add_actions(env);
				add_is_draw_bonus(env);
				if (ISRR)
					wolf_rendering_rc(env);
			}
		}
	}
	wolf_free(&env);
}
