/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering_mainmenu.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:01:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/27 22:31:35 by tmaluh           ###   ########.fr       */
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
	point	p;

	p.y = -1;
	while (++(p.y) < env->menu->selector->surf->h && (p.x = -1))
		while (++(p.x) < env->menu->selector->surf->w)
			env->sdl->win_pixels[p.y * WIN_X + p.x] =
				env->menu->selector->pixels[
					p.y * env->menu->selector->surf->w + p.x];
}

void		wolf_rendering_mainmenu(t_env *env)
{
	add_draw_bg_text(env);
	add_draw_selector(env);
	SDL_UpdateWindowSurface(env->sdl->win);
}
