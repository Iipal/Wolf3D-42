/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering_colored.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:22:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/18 11:50:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int	add_choose_current_color(t_env *env)
{
	int	tex;

	(RC->step.x < 0) ? (tex = 1)
		: (tex = 2);
	if (RC->is_side)
		(RC->step.y < 0) ? (tex = 3)
			: (tex = 4);
	return (MAPC[RC->map.y][RC->map.x] / tex);
}

void		wolf_render_colored(t_env *env, point *p)
{
	int	current_color;

	current_color = add_choose_current_color(env);
	if (RC->is_side)
		current_color /= 2;
	p->y = RC->draw_start;
	while (p->y <= RC->draw_end)
		if (ISRF)
			SWINP[(p->y)++ * WIN_X + p->x] =
				wolf_fog(RC->pwd, current_color, RC->fog_color, RC->fog_dist);
		else
			SWINP[(p->y)++ * WIN_X + p->x] = current_color;
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
