/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:03:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/09 18:10:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_set_diststep(t_env *env)
{
	if (RC->ray_dir.x < 0)
	{
		RC->step.x = -1;
		RC->side_dist.x = (RC->pos.x - RC->map.x) * RC->delta_dist.x;
	}
	else
	{
		RC->step.x = 1;
		RC->side_dist.x = (RC->map.x + 1.0 - RC->pos.x) * RC->delta_dist.x;
	}
	if (RC->ray_dir.y < 0)
	{
		RC->step.y = -1;
		RC->side_dist.y = (RC->pos.y - RC->map.y) * RC->delta_dist.y;
	}
	else
	{
		RC->step.y = 1;
		RC->side_dist.y = (RC->map.y + 1.0 - RC->pos.y) * RC->delta_dist.y;
	}
}

static void	add_check_hit(t_env *env)
{
	while (!RC->is_hit)
	{
		if (RC->side_dist.x < RC->side_dist.y)
		{
			RC->side_dist.x += RC->delta_dist.x;
			RC->map.x += RC->step.x;
			RC->is_side = false;
		}
		else
		{
			RC->side_dist.y += RC->delta_dist.y;
			RC->map.y += RC->step.y;
			RC->is_side = true;
		}
		if (MAP[RC->map.y][RC->map.x] > 0)
			RC->is_hit = true;
	}
}

static void	add_set_draw_area(t_env *env, point *p)
{
	if (!RC->is_side)
		RC->pwd = (RC->map.x
			- RC->pos.x + (1 - RC->step.x) / 2) / RC->ray_dir.x;
	else
		RC->pwd = (RC->map.y
			- RC->pos.y + (1 - RC->step.y) / 2) / RC->ray_dir.y;
	RC->hline = (int)(WIN_Y / RC->pwd);
	RC->draw_start = -(RC->hline) / 2 + WIN_Y / 2;
	RC->draw_end = RC->hline / 2 + WIN_Y / 2;
	if (RC->draw_start < 0)
		RC->draw_start = 0;
	if ((ull)RC->draw_end >= (ull)WIN_Y)
		RC->draw_end = WIN_Y - 1;
	RC->current_color = MAPC[RC->map.y][RC->map.x];
	if (RC->is_side)
		RC->current_color /= 2;
	p->y = RC->draw_start;
	while (++(p->y) < RC->draw_end)
		SPTR[p->y * WIN_X + p->x] = RC->current_color;
}

void		wolf_rendering(t_env *env)
{
	point	p;

	p.x = -1;
	while (++(p.x) < WIN_X)
	{
		*(RC) = (t_rc){{RC->pos.y, RC->pos.x}, {0, -1}, {0.66, 0},
			2 * p.x / (double)WIN_X - 1, {0, 0}, {0, 0}, {0, 0}, {0, 0},
			0, {0, 0}, false, false, 0, 0, 0, 0};
		RC->ray_dir = (fpoint) { RC->dir.y + RC->plane.y * RC->xcamera,
			RC->dir.x + RC->plane.x * RC->xcamera };
		RC->map = (point) {(int)RC->pos.y, (int)RC->pos.x};
		RC->delta_dist = (fpoint){_ABS(RC->ray_dir.y), _ABS(RC->ray_dir.x)};
		add_set_diststep(env);
		add_check_hit(env);
		add_set_draw_area(env, &p);
	}
	mlx_put_image_to_window(MPTR, WPTR, IPTR, 0, 0);
}
