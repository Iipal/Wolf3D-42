/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:03:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/13 15:27:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_render_floor(t_env *env, t_texhelper *tx, point *p)
{
	t_floorhelper	h;

	if (!RC->is_side && RC->raydir.x > 0)
		h.fpos = (fpoint){RC->map.y + tx->where_is_hit, RC->map.x};
	else if (!RC->is_side && RC->raydir.x < 0)
		h.fpos = (fpoint){RC->map.y + tx->where_is_hit, RC->map.x + 1.0};
	else if (RC->is_side && RC->raydir.y > 0)
		h.fpos = (fpoint){RC->map.y, RC->map.x + tx->where_is_hit};
	else
		h.fpos = (fpoint){RC->map.y + 1.0, RC->map.x + tx->where_is_hit};
	h.dist_wall = RC->pwd;
	h.dist_player = 0.0;
	if (RC->draw_end < 0)
		RC->draw_end = WIN_Y;
	p->y = RC->draw_end + 1;
	while (p->y < WIN_Y)
	{
		h.current_dist = WIN_Y / (2.0 * p->y - WIN_Y);
		h.weight = (h.current_dist - h.dist_player) / (h.dist_wall - h.dist_player);
		h.fcur.y = h.weight * h.fpos.y + (1.0 - h.weight) * RC->pos.y;
		h.fcur.x = h.weight * h.fpos.x + (1.0 - h.weight) * RC->pos.x;
		h.ftex.y = (int)(h.fcur.y * YTEX) % YTEX;
		h.ftex.x = (int)(h.fcur.x * XTEX) % XTEX;
		h.check_board = (int)(h.fcur.x + h.fcur.y) % 2;
		SPTR[(p->y)++ * WIN_X + p->x] = (TEX[FLOOR].img[h.ftex.y * XTEX + h.ftex.x] >> 1) & 8355711;
	}
}

static void	add_render_textured(t_env *env, point *p)
{
	t_texhelper	h;

	h.curr_tex = MAP[RC->map.y][RC->map.x] - 1;
	if (!RC->is_side)
		h.where_is_hit = RC->pos.y + RC->pwd * RC->raydir.y;
	else
		h.where_is_hit = RC->pos.x + RC->pwd * RC->raydir.x;
	h.where_is_hit -= floor(h.where_is_hit);
	h.pos_on_tex.x = (int)(h.where_is_hit * (double)(XTEX));
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

static void	add_render_colored(t_env *env, point *p)
{
	int		current_color;

	current_color = MAPC[RC->map.y][RC->map.x];
	if (RC->is_side)
		current_color /= 2;
	p->y = RC->draw_start;
	while (p->y <= RC->draw_end)
		SPTR[(p->y)++ * WIN_X + p->x] = current_color;
}

void		add_fill_floor_is_colored(t_mlx *mlx)
{
	point	p;

	p.y = -1;
	while (++(p.y) < WIN_Y && (p.x = -1))
		while (++(p.x) < WIN_X)
			mlx->screen[p.y * WIN_X + p.x] = (p.y >= WIN_Y / 2) ? IRGB_GRAY : 0;
}

void		wolf_rendering_rc(t_env *env)
{
	point	p;

	ft_bzero(SPTR, sizeof(int) * WIN_X * WIN_Y);
	if (!ISRT)
		add_fill_floor_is_colored(env->mlx);
	p.x = -1;
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
		ISRT ? add_render_textured(env, &p) : add_render_colored(env, &p);
	}
	mlx_put_image_to_window(MPTR, WPTR, IPTR, 0, 0);
}
