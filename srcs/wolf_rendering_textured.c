/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering_textured.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:41:02 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/18 11:09:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_render_floor_init_fpos(t_env *env, t_texhelper *tx,
										t_floorhelper *h)
{
	if (!RC->is_side && RC->raydir.x > 0)
		h->fpos = (fpoint){RC->map.y + tx->where_is_hit, RC->map.x};
	else if (!RC->is_side && RC->raydir.x < 0)
		h->fpos = (fpoint){RC->map.y + tx->where_is_hit, RC->map.x + 1.0};
	else if (RC->is_side && RC->raydir.y > 0)
		h->fpos = (fpoint){RC->map.y, RC->map.x + tx->where_is_hit};
	else
		h->fpos = (fpoint){RC->map.y + 1.0, RC->map.x + tx->where_is_hit};
}

void	add_is_render_fog(t_floorhelper *h, t_env *env, point *p, float d)
{
	Uint32	currfloor;
	Uint32	currsky;
	int		fscreen;
	int		sscreen;

	fscreen = p->y * WIN_X + p->x;
	sscreen = (WIN_Y - p->y) * WIN_X + p->x;
	currfloor = (TEX[TFLOOR].pixels[h->ftex.y * XTEX + h->ftex.x] >> 1) & 8355711;
	currsky = TEX[TSKY].pixels[XTEX * h->ftex.y + h->ftex.x];
	if (ISRF)
	{
		SWINP[fscreen] = wolf_fog(d, currfloor, RC->fog_color, RC->fog_dist);
		SWINP[sscreen] = wolf_fog(d, currsky, RC->fog_color, RC->fog_dist);
	}
	else
	{
		SWINP[fscreen] = currfloor;
		SWINP[sscreen] = currsky;
	}
}

static void	add_render_floornceiling(t_env *env, t_texhelper *tx, point *p)
{
	t_floorhelper	h;

	add_render_floor_init_fpos(env, tx, &h);
	if (RC->draw_end < 0)
		RC->draw_end = WIN_Y;
	p->y = RC->draw_end - 1;
	while (++p->y < WIN_Y)
	{
		h.currd = WIN_Y / (2.0 * p->y - WIN_Y);
		h.weight = (h.currd - 0.0) / (RC->pwd - 0.0);
		h.fcur.y = h.weight * h.fpos.y + (1.0 - h.weight) * RC->pos.y;
		h.fcur.x = h.weight * h.fpos.x + (1.0 - h.weight) * RC->pos.x;
		h.ftex = (point){(int)(h.fcur.y * YTEX) % YTEX,
			(int)(h.fcur.x * XTEX) % XTEX};
		add_is_render_fog(&h, env, p, h.currd);
	}
}

static void	add_choose_current_texture(t_env *env, t_texhelper *h)
{
	int	tex;

	h->curr_tex = MAP[RC->map.y][RC->map.x] - 1;
	(RC->step.x < 0) ? (tex = 0)
		: (tex = 1);
	if (RC->is_side)
		(RC->step.y < 0) ? (tex = 2)
			: (tex = 3);
	if ((h->curr_tex += tex) > MAX_TEXTURES + 1)
		h->curr_tex -= (MAX_TEXTURES + 1);
}

void		wolf_render_textured(t_env *env, point *p)
{
	t_texhelper	h;

	add_choose_current_texture(env, &h);
	if (!RC->is_side)
		h.where_is_hit = RC->pos.y + RC->pwd * RC->raydir.y;
	else
		h.where_is_hit = RC->pos.x + RC->pwd * RC->raydir.x;
	h.where_is_hit -= (int)h.where_is_hit;
	h.pos_on_tex.x = (int)(h.where_is_hit * XTEX);
	if ((!RC->is_side && RC->raydir.x > 0)
	|| (RC->is_side && RC->raydir.y > 0))
		h.pos_on_tex.x = XTEX - h.pos_on_tex.x - 1;
	p->y = RC->draw_start;
	while (p->y < RC->draw_end)
	{
		h.d = p->y * 256 - WIN_Y * 128 + RC->hline * 128;
		h.pos_on_tex.y = ((h.d * YTEX) / RC->hline) / 256;
		h.currtcolor = TEX[h.curr_tex].pixels[h.pos_on_tex.y * YTEX + h.pos_on_tex.x];
		if (RC->is_side)
			h.currtcolor = (h.currtcolor >> 1) & 8355711;
		if (ISRF)
			SWINP[(p->y)++ * WIN_X + p->x] = wolf_fog(RC->pwd, h.currtcolor, RC->fog_color, RC->fog_dist);
		else
			SWINP[(p->y)++ * WIN_X + p->x] = h.currtcolor;
	}
	add_render_floornceiling(env, &h, p);
}
