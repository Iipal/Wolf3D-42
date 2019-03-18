/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:13:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/16 22:22:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	add_set_diststep(t_rc *rc)
{
	if (rc->raydir.x < 0)
	{
		rc->step.x = -1;
		rc->side_dist.x = (rc->pos.x - rc->map.x) * rc->ddist.x;
	}
	else
	{
		rc->step.x = 1;
		rc->side_dist.x = (rc->map.x + 1.0 - rc->pos.x) * rc->ddist.x;
	}
	if (rc->raydir.y < 0)
	{
		rc->step.y = -1;
		rc->side_dist.y = (rc->pos.y - rc->map.y) * rc->ddist.y;
	}
	else
	{
		rc->step.y = 1;
		rc->side_dist.y = (rc->map.y + 1.0 - rc->pos.y) * rc->ddist.y;
	}
}

static void	add_check_hit(t_rc *rc, itab map)
{
	while (!rc->is_hit)
	{
		if (rc->side_dist.x < rc->side_dist.y)
		{
			rc->side_dist.x += rc->ddist.x;
			rc->map.x += rc->step.x;
			rc->is_side = false;
		}
		else
		{
			rc->side_dist.y += rc->ddist.y;
			rc->map.y += rc->step.y;
			rc->is_side = true;
		}
		if (map[rc->map.y][rc->map.x] > 0)
			rc->is_hit = true;
	}
}

static void	add_dist_to_wall(t_rc *rc)
{
	!rc->is_side
	? (rc->pwd = (rc->map.x - rc->pos.x + (1 - rc->step.x) / 2) / rc->raydir.x)
	: (rc->pwd = (rc->map.y - rc->pos.y + (1 - rc->step.y) / 2) / rc->raydir.y);
	rc->hline = (int)(WIN_Y / rc->pwd);
	rc->draw_start = -(rc->hline) / 2 + WIN_Y / 2;
	rc->draw_end = rc->hline / 2 + WIN_Y / 2;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	if (rc->draw_end >= WIN_Y)
		rc->draw_end = WIN_Y - 1;
}

static void	add_fill_floornceiling(t_sdl *sdl)
{
	point	p;

	p.y = -1;
	while (++(p.y) < WIN_Y && (p.x = -1))
		while (++(p.x) < WIN_X)
			sdl->win_pixels[p.y * WIN_X + p.x] =
				(p.y >= WIN_Y / 2) ? IRGB_FLOOR : IRGB_SKY;
}

void		wolf_raycaster(t_env *env)
{
	point	p;

	p.x = -1;
	if (!env->isr->is_textured)
		add_fill_floornceiling(env->sdl);
	while (++(p.x) < WIN_X)
	{
		*(env->rc) = (t_rc){{RC->pos.y, RC->pos.x}, {RC->dir.y, RC->dir.x},
		{RC->plane.y, RC->plane.x}, 0, {0, 0}, {0, 0}, {0, 0}, {0, 0}, 0,
		{0, 0}, false, false, 0, 0, 0};
		RC->xcamera = 2 * p.x / (double)WIN_X - 1;
		env->rc->raydir = (fpoint){RC->dir.y + RC->plane.y * RC->xcamera,
			env->rc->dir.x + env->rc->plane.x * env->rc->xcamera };
		env->rc->map = (point){(int)env->rc->pos.y, (int)env->rc->pos.x};
		RC->ddist = (fpoint){_ABS(1 / RC->raydir.y), _ABS(1 / RC->raydir.x)};
		add_set_diststep(env->rc);
		add_check_hit(env->rc, env->map->tab);
		add_dist_to_wall(env->rc);
		ISRT ? wolf_render_textured(env, &p) : wolf_render_colored(env, &p);
	}
}