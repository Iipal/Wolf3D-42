/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_main_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:01:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/05 11:05:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		wolf_rendering_mainmenu(t_env *env)
{
	const int32_t	selector_shifts[] = {SPOS_EXIT, SPOS_START};
	fpoint			selector_range;
	point			tp;
	point			p;

	p.y = -1;
	tp.y = 0;
	selector_range = (fpoint){SELECTOR_START_Y +
		selector_shifts[env->menu->is_selector_start], SELECTOR_START_X};
	while (++(p.y) < WIN_Y && (p.x = -1)
	&& (tp.x = -1))
	{
		while (++(p.x) < WIN_X)
		{
			env->sdl->win_pixels[p.y * WIN_X + p.x] =
					env->menu->bg->pixels[p.y * WIN_X + p.x];
			if (p.y >= selector_range.y && p.y < selector_range.y + SELECTOR_Y
			&& p.x >= selector_range.x && p.x < selector_range.x + SELECTOR_X)
				env->sdl->win_pixels[p.y * WIN_X + p.x] =
					env->menu->selector->pixels[tp.y * SELECTOR_X + ++(tp.x)];
		}
		if (p.y >= selector_range.y && p.y < selector_range.y + SELECTOR_Y)
			++(tp.y);
	}
	SDL_UpdateWindowSurface(env->sdl->win);
}
