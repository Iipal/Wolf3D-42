/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_colored.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:22:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 00:30:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static Uint32	add_choose_current_color(t_env *env)
{
	Uint32	tex;

	(env->rc->step.x < 0) ? (tex = 1)
		: (tex = 2);
	if (env->rc->is_side)
		(env->rc->step.y < 0) ? (tex = 3)
			: (tex = 4);
	return (env->map->colors[env->rc->map.y][env->rc->map.x] / tex);
}

void			wolf_render_colored(t_env *env, point *p)
{
	Uint32	current_color;

	current_color = add_choose_current_color(env);
	if (env->rc->is_side)
		current_color /= 2;
	p->y = env->rc->draw_start - 1;
	while (++(p->y) <= env->rc->draw_end)
		if (env->isr->is_render_fog)
		{
			if (env->rc->pwd >= env->fog.fog_dist)
				env->sdl->win_pixels[p->y * WIN_X + p->x] = env->fog.fog_color;
			else
				env->sdl->win_pixels[p->y * WIN_X + p->x] =
					wolf_fog(env->rc->pwd, current_color, &(env->fog));
		}
		else
			env->sdl->win_pixels[p->y * WIN_X + p->x] = current_color;
}
