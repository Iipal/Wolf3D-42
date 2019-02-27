/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering_textured.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:41:02 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/27 22:40:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_render_floor_init_fpos(t_env *env, t_texhelper *tx,
										t_floorhelper *h)
{
	if (!env->rc->is_side && env->rc->raydir.x > 0)
		h->fpos = (fpoint){env->rc->map.y + tx->where_is_hit, env->rc->map.x};
	else if (!env->rc->is_side && env->rc->raydir.x < 0)
		h->fpos = (fpoint){env->rc->map.y + tx->where_is_hit,
			env->rc->map.x + 1.0};
	else if (env->rc->is_side && env->rc->raydir.y > 0)
		h->fpos = (fpoint){env->rc->map.y, env->rc->map.x + tx->where_is_hit};
	else
		h->fpos = (fpoint){env->rc->map.y + 1.0,
			env->rc->map.x + tx->where_is_hit};
}

static void	add_is_render_fog(t_floorhelper *h,
	t_env *env, point *p, float fog_distance)
{
	const Uint32	curr_floor = (env->textures[TFLOOR].pixels[
		h->ftex.y * XTEX + h->ftex.x] >> 1) & FCL;
	const Uint32	curr_sky = TEX[TSKY].pixels[h->ftex.y * XTEX + h->ftex.x];
	const Uint32	fog_color = env->fog.fog_color;

	if (env->isr->is_render_fog)
	{
		if (fog_distance >= env->fog.fog_dist)
		{
			env->sdl->win_pixels[p->y * WIN_X + p->x] = fog_color;
			env->sdl->win_pixels[(WIN_Y - p->y) * WIN_X + p->x] = fog_color;
		}
		else
		{
			env->sdl->win_pixels[p->y * WIN_X + p->x] =
				wolf_fog(fog_distance, curr_floor, &(env->fog));
			env->sdl->win_pixels[(WIN_Y - p->y) * WIN_X + p->x] =
				wolf_fog(fog_distance, curr_sky, &(env->fog));
		}
	}
	else
	{
		env->sdl->win_pixels[p->y * WIN_X + p->x] = curr_floor;
		env->sdl->win_pixels[(WIN_Y - p->y) * WIN_X + p->x] = curr_sky;
	}
}

static void	add_render_floornceiling(t_env *env, t_texhelper *tx, point *p)
{
	t_floorhelper	h;

	add_render_floor_init_fpos(env, tx, &h);
	if (env->rc->draw_end < 0)
		env->rc->draw_end = WIN_Y;
	p->y = env->rc->draw_end;
	while (p->y < WIN_Y)
	{
		h.currd = WIN_Y / (2.0 * p->y - WIN_Y);
		h.weight = (h.currd - 0.0) / (env->rc->pwd - 0.0);
		h.fcur.y = h.weight * h.fpos.y + (1.0 - h.weight) * env->rc->pos.y;
		h.fcur.x = h.weight * h.fpos.x + (1.0 - h.weight) * env->rc->pos.x;
		h.ftex = (point){(int)(h.fcur.y * YTEX) % YTEX,
			(int)(h.fcur.x * XTEX) % XTEX};
		add_is_render_fog(&h, env, p, h.currd);
		++(p->y);
	}
}

static void	add_choose_current_texture(t_env *env, t_texhelper *h)
{
	int	tex;

	h->curr_tex = env->map->tab[RC->map.y][RC->map.x] - 1;
	(env->rc->step.x < 0) ? (tex = 0)
		: (tex = 1);
	if (env->rc->is_side)
		(env->rc->step.y < 0) ? (tex = 2)
			: (tex = 3);
	if ((h->curr_tex += tex) > MAX_TEXTURES + 1)
		h->curr_tex -= (MAX_TEXTURES + 1);
}

void		wolf_render_textured(t_env *env, point *p)
{
	t_texhelper	h;

	add_choose_current_texture(env, &h);
	if (!env->rc->is_side)
		h.where_is_hit = env->rc->pos.y + env->rc->pwd * env->rc->raydir.y;
	else
		h.where_is_hit = env->rc->pos.x + env->rc->pwd * env->rc->raydir.x;
	h.where_is_hit -= (int)h.where_is_hit;
	h.pos_on_tex.x = (int)(h.where_is_hit * XTEX);
	if ((!env->rc->is_side && env->rc->raydir.x > 0)
	|| (env->rc->is_side && env->rc->raydir.y > 0))
		h.pos_on_tex.x = XTEX - h.pos_on_tex.x - 1;
	wolf_render_textured_help(env, p, &h);
	add_render_floornceiling(env, &h, p);
}
