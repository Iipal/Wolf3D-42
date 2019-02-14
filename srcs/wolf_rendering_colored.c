/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering_colored.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:22:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/14 13:58:44 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wolf_render_colored(itab colors, iarr screen, point *p, t_rc *rc)
{
	int	current_color;

	current_color = colors[rc->map.y][rc->map.x];
	if (rc->is_side)
		current_color /= 2;
	p->y = rc->draw_start;
	while (p->y <= rc->draw_end)
		screen[(p->y)++ * WIN_X + p->x] = current_color;
}

void	wolf_fill_floor_if_colored_rc(iarr screen)
{
	point	p;

	p.y = -1;
	while (++(p.y) < WIN_Y && (p.x = -1))
		while (++(p.x) < WIN_X)
			screen[p.y * WIN_X + p.x] =
				(p.y >= WIN_Y / 2) ? IRGB_FLOOR : IRGB_SKY;
}
