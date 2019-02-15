/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:03:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/15 23:06:36 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_draw_bonus(t_env *env)
{
	if (ISRMM)
		wolf_draw_minimap(env);
}

void		wolf_rendering_rc(t_env *env)
{
	point	p;

	p.x = -1;
	if (!ISRT)
		wolf_fill_floor_if_colored_rc(env->sdl);
	while (++(p.x) < WIN_X)
	{
		*(RC) = (t_rc){{RC->pos.y, RC->pos.x}, {RC->dir.y, RC->dir.x},
		{RC->plane.y, RC->plane.x}, 0, {0, 0}, {0, 0}, {0, 0}, {0, 0},
		0, {0, 0}, false, false, 0, 0, 0};
		RC->xcamera = 2 * p.x / (double)WIN_X - 1;
		RC->raydir = (fpoint){RC->dir.y + RC->plane.y * RC->xcamera,
			RC->dir.x + RC->plane.x * RC->xcamera };
		RC->map = (point){(int)RC->pos.y, (int)RC->pos.x};
		RC->absdist = (fpoint){_ABS(1 / RC->raydir.y), _ABS(1 / RC->raydir.x)};
		wolf_set_diststep(RC);
		wolf_check_hit(RC, MAP);
		wolf_set_draw_area(RC);
		ISRT ? wolf_render_textured(env, &p) : wolf_render_colored(env, &p);
	}
	add_draw_bonus(env);
	SDL_UpdateWindowSurface(SWIN);
}
