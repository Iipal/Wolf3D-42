/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering_mainmenu.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:01:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/27 17:36:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_draw_bg_text(t_env *env)
{
	point		p;
	point		tp;
	const float	text_shift_x = TEXT_SHIFT_X;
	const float	text_shift_y = TEXT_SHIFT_Y;

	p.y = -1;
	tp.y = 0;
	while (++(p.y) < WIN_Y && (p.x = -1)
			&& !(tp.x = 0))
	{
		while (++(p.x) < WIN_X)
		{
			SWINP[p.y * WIN_X + p.x] = MENUP[p.y * WIN_X + p.x];
			if (p.x >= text_shift_x && p.x < text_shift_x + MENU->text->surf->w)
			{
				if (MTEXTP[tp.y * MENU->text->surf->w + tp.x] == IARGB_WHITE)
					SWINP[p.y * WIN_X + p.x] =
						MTEXTP[tp.y * MENU->text->surf->w + tp.x];
				++(tp.x);
			}
		}
		if (p.y >= text_shift_y && p.y < text_shift_y + MENU->text->surf->h)
			++(tp.y);
	}
}

void		wolf_rendering_mainmenu(t_env *env)
{
	add_draw_bg_text(env);
	SDL_UpdateWindowSurface(SWIN);
}
