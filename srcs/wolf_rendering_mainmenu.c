/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering_mainmenu.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:01:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/28 12:05:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_draw_bg_text(t_env *env)
{
	point	p;

	p.y = -1;
	while (++(p.y) < WIN_Y && (p.x = -1))
		while (++(p.x) < WIN_X)
			env->sdl->win_pixels[p.y * WIN_X + p.x] =
				env->menu->bg->pixels[p.y * WIN_X + p.x];
}

static void	add_draw_selector(t_env *env)
{
	const int	selector_shifts[] = {SPOS_START, SPOS_OPTIONS, SPOS_EXIT};
	fpoint		selector_range;
	point		p;
	point		tp;

	selector_range = (fpoint){SELECTOR_START_Y +
		selector_shifts[env->menu->selector_shift], SELECTOR_START_X};
	p.y = selector_range.y;
	tp.y = 0;
	while (++(p.y) < selector_range.y + SELECTOR_Y && (p.x = selector_range.x)
		&& (tp.x = -1))
	{
		while (++(p.x) < selector_range.x + SELECTOR_X)
			env->sdl->win_pixels[p.y * WIN_X + p.x] =
				env->menu->selector->pixels[tp.y * SELECTOR_X + ++(tp.x)];
		++(tp.y);
	}
}

void		wolf_rendering_mainmenu(t_env *env)
{
	add_draw_bg_text(env);
	add_draw_selector(env);
	SDL_UpdateWindowSurface(env->sdl->win);
}
