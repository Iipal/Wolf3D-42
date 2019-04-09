/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_colored.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:22:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 23:20:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static Uint32	add_choose_current_color(t_env *env)
{
	Uint32	tex;

	(0 > env->rc->step.x) ? (tex = 1)
		: (tex = 2);
	if (true == env->rc->is_side)
		(0 > env->rc->step.y) ? (tex = 3)
			: (tex = 4);
	return (env->map->colors[env->rc->map.y][env->rc->map.x] / tex);
}

void			wolf_render_colored(t_env *env, point *p)
{
	Uint32	current_color;

	current_color = add_choose_current_color(env);
	IFDO(env->rc->is_side, current_color /= 2);
	p->y = env->rc->draw_start - 1;
	while (env->rc->draw_end >= ++(p->y))
		if (true == env->isr->is_render_fog)
		{
			if (env->fog.fog_dist <= env->rc->pwd)
				env->sdl->win_pixels[p->y * WIN_X + p->x] = env->fog.fog_color;
			else
				env->sdl->win_pixels[p->y * WIN_X + p->x] =
					wolf_fog(env->rc->pwd, current_color, &(env->fog));
		}
		else
			env->sdl->win_pixels[p->y * WIN_X + p->x] = current_color;
}
