/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_textured.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:41:02 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 23:37:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	add_render_floor_init_fpos(t_env *env, t_texhelp *tx,
										t_floorhelper *h)
{
	if (!env->rc->is_side && 0 < env->rc->raydir.x)
		h->fpos = (fpoint){env->rc->map.y + tx->where_is_hit, env->rc->map.x};
	else if (!env->rc->is_side && 0 > env->rc->raydir.x)
		h->fpos = (fpoint){env->rc->map.y + tx->where_is_hit,
			env->rc->map.x + 1.0};
	else if (env->rc->is_side && 0 < env->rc->raydir.y)
		h->fpos = (fpoint){env->rc->map.y, env->rc->map.x + tx->where_is_hit};
	else
		h->fpos = (fpoint){env->rc->map.y + 1.0,
			env->rc->map.x + tx->where_is_hit};
}

static void	add_is_render_fog(t_floorhelper *h, t_env *env,
								point *p, float fog_distance)
{
	const Uint32	curr_floor = (env->floor_and_sky->pixels[FPOS] >> 1) & FCL;
	const Uint32	curr_sky = env->floor_and_sky->pixels[SPOS];
	const Uint32	fog_color = env->fog.fog_color;

	if (env->isr->is_render_fog)
	{
		if (env->fog.fog_dist <= fog_distance)
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

static void	add_render_floornceiling(t_env *env, t_texhelp *tx, point *p)
{
	t_floorhelper	h;

	add_render_floor_init_fpos(env, tx, &h);
	IFDO(env->rc->draw_end < 0, env->rc->draw_end = WIN_Y);
	p->y = env->rc->draw_end;
	while (WIN_Y > p->y)
	{
		h.currd = WIN_Y / (2.0 * p->y - WIN_Y);
		h.weight = (h.currd - 0.0) / (env->rc->pwd - 0.0);
		h.fcur.y = h.weight * h.fpos.y + (1.0 - h.weight) * env->rc->pos.y;
		h.fcur.x = h.weight * h.fpos.x + (1.0 - h.weight) * env->rc->pos.x;
		h.ftex = (point){(int32_t)(h.fcur.y * WALLS_BLOCK_SIZE)
									% WALLS_BLOCK_SIZE,
			(int32_t)(h.fcur.x * WALLS_BLOCK_SIZE) % WALLS_BLOCK_SIZE};
		add_is_render_fog(&h, env, p, h.currd);
		++(p->y);
	}
}

inline void	add_choose_current_texture(t_env *env, int32_t *curr_tex)
{
	uint8_t	tex;

	*curr_tex = env->map->tab[RC->map.y][RC->map.x] - 1;
	(0 > env->rc->step.x) ? (tex = 0)
		: (tex = 1);
	if (env->rc->is_side)
		(0 > env->rc->step.y) ? (tex = 2)
			: (tex = 3);
	if (env->walls->max_textures - 1 < (*curr_tex += tex))
		*curr_tex -= (env->walls->max_textures - 1);
}

void		wolf_render_textured(t_env *env, point *p)
{
	t_texhelp	h;

	add_choose_current_texture(env, &h.curr_tex);
	if (!env->rc->is_side)
		h.where_is_hit = env->rc->pos.y + env->rc->pwd * env->rc->raydir.y;
	else
		h.where_is_hit = env->rc->pos.x + env->rc->pwd * env->rc->raydir.x;
	h.where_is_hit -= (int32_t)h.where_is_hit;
	h.pos_on_tex.x = (int32_t)(h.where_is_hit * WALLS_BLOCK_SIZE);
	if ((!env->rc->is_side && 0 < env->rc->raydir.x)
	|| (env->rc->is_side && 0 < env->rc->raydir.y))
		h.pos_on_tex.x = WALLS_BLOCK_SIZE - h.pos_on_tex.x - 1;
	wolf_render_textured_draw_line(env, p, &h);
	add_render_floornceiling(env, &h, p);
}
