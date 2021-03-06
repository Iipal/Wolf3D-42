/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_textured_draw_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:59:37 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/10 11:11:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_render_textured_draw_line(t_env *env, point *p, t_texhelp *h)
{
	p->y = env->rc->draw_start;
	while (env->rc->draw_end > p->y)
	{
		h->d = p->y * 256 - WIN_Y * 128 + env->rc->hline * 128;
		h->pos_on_tex.y = ((h->d * WALLS_BLOCK_SIZE) / env->rc->hline) / 256;
		IFDO(0 > h->pos_on_tex.y, h->pos_on_tex.y = 0);
		h->currtcolor = env->walls->data->pixels
		[(env->walls->start[h->curr_tex].y + h->pos_on_tex.y)
		* env->walls->data->surf->w
		+ (env->walls->start[h->curr_tex].x + h->pos_on_tex.x)];
		IFDO(env->rc->is_side, h->currtcolor = (h->currtcolor >> 1) & FCL);
		if (env->isr->is_render_fog)
		{
			if (env->fog.fog_dist <= env->rc->pwd)
				env->sdl->win_pixels[p->y * WIN_X + p->x] = env->fog.fog_color;
			else
				env->sdl->win_pixels[p->y * WIN_X + p->x] =
					wolf_fog(env->rc->pwd, h->currtcolor, &(env->fog));
		}
		else
			env->sdl->win_pixels[p->y * WIN_X + p->x] = h->currtcolor;
		++p->y;
	}
}
