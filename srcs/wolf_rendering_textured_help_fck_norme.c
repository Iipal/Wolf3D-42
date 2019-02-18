/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering_textured_help_fck_norme.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:59:37 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/18 12:02:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wolf_render_textured_help(t_env *env, point *p, t_texhelper *h)
{
	p->y = RC->draw_start;
	while (p->y < RC->draw_end)
	{
		h->d = p->y * 256 - WIN_Y * 128 + RC->hline * 128;
		h->pos_on_tex.y = ((h->d * YTEX) / RC->hline) / 256;
		h->currtcolor =
			TEX[h->curr_tex].pixels[h->pos_on_tex.y * YTEX + h->pos_on_tex.x];
		if (RC->is_side)
			h->currtcolor = (h->currtcolor >> 1) & 8355711;
		if (ISRF)
			SWINP[(p->y)++ * WIN_X + p->x] =
				wolf_fog(RC->pwd, h->currtcolor, RC->fog_color, RC->fog_dist);
		else
			SWINP[(p->y)++ * WIN_X + p->x] = h->currtcolor;
	}
}
