/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:41:02 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/13 18:15:11 by tmaluh           ###   ########.fr       */
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

static void	add_render_floor(t_env *env, t_texhelper *tx, point *p)
{
	t_floorhelper	h;

	add_render_floor_init_fpos(env, tx, &h);
	h.dist_wall = RC->pwd;
	h.dist_player = 0.0;
	if (RC->draw_end < 0)
		RC->draw_end = WIN_Y;
	p->y = RC->draw_end + 1;
	while (p->y < WIN_Y)
	{
		h.current_dist = WIN_Y / (2.0 * p->y - WIN_Y);
		h.weight = (h.current_dist - h.dist_player)
					/ (h.dist_wall - h.dist_player);
		h.fcur.y = h.weight * h.fpos.y + (1.0 - h.weight) * RC->pos.y;
		h.fcur.x = h.weight * h.fpos.x + (1.0 - h.weight) * RC->pos.x;
		h.ftex.y = (int)(h.fcur.y * YTEX) % YTEX;
		h.ftex.x = (int)(h.fcur.x * XTEX) % XTEX;
		h.check_board = (int)(h.fcur.x + h.fcur.y) % 2;
		SPTR[p->y * WIN_X + p->x] =
			(TEX[TFLOOR].img[h.ftex.y * XTEX + h.ftex.x] >> 1) & 8355711;
		SPTR[(WIN_Y - (p->y)++) * WIN_X + p->x] =
			(TEX[TSKY].img[XTEX * h.ftex.y + h.ftex.x]);
	}
}

void		wolf_render_textured(t_env *env, point *p)
{
	t_texhelper	h;

	h.curr_tex = MAP[RC->map.y][RC->map.x] - 1;
	if (!RC->is_side)
		h.where_is_hit = RC->pos.y + RC->pwd * RC->raydir.y;
	else
		h.where_is_hit = RC->pos.x + RC->pwd * RC->raydir.x;
	h.where_is_hit -= floor(h.where_is_hit);
	h.pos_on_tex.x = (int)(h.where_is_hit * (double)XTEX);
	if (!RC->is_side && RC->raydir.x > 0)
		h.pos_on_tex.x = XTEX - h.pos_on_tex.x - 1;
	if (RC->is_side && RC->raydir.y > 0)
		h.pos_on_tex.x = XTEX - h.pos_on_tex.x - 1;
	p->y = RC->draw_start;
	while (p->y < RC->draw_end)
	{
		h.d = p->y * 256 - WIN_Y * 128 + RC->hline * 128;
		h.pos_on_tex.y = ((h.d * YTEX) / RC->hline) / 256;
		h.curr_color_on_tex = TEX[h.curr_tex].img[
					h.pos_on_tex.y * YTEX + h.pos_on_tex.x];
		if (RC->is_side)
			h.curr_color_on_tex = (h.curr_color_on_tex >> 1) & 8355711;
		SPTR[(p->y)++ * WIN_X + p->x] = h.curr_color_on_tex;
	}
	add_render_floor(env, &h, p);
}
