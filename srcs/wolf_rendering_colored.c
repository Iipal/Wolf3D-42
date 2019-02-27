/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering_colored.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:22:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/27 22:32:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int	add_choose_current_color(t_env *env)
{
	int	tex;

	(env->rc->step.x < 0) ? (tex = 1)
		: (tex = 2);
	if (env->rc->is_side)
		(env->rc->step.y < 0) ? (tex = 3)
			: (tex = 4);
	return (env->map->colors[env->rc->map.y][env->rc->map.x] / tex);
}

void		wolf_render_colored(t_env *env, point *p)
{
	int	current_color;

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

void		wolf_fill_floor_if_colored_rc(t_sdl *sdl)
{
	point	p;

	p.y = -1;
	while (++(p.y) < WIN_Y && (p.x = -1))
		while (++(p.x) < WIN_X)
			sdl->win_pixels[p.y * WIN_X + p.x] =
				(p.y >= WIN_Y / 2) ? IRGB_FLOOR : IRGB_SKY;
}
