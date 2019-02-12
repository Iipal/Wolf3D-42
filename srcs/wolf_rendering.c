/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:03:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/12 19:03:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_set_diststep(t_rc *rc)
{
	if (rc->ray_dir.x < 0)
	{
		rc->step.x = -1;
		rc->side_dist.x = (rc->pos.x - rc->map.x) * rc->absdist.x;
	}
	else
	{
		rc->step.x = 1;
		rc->side_dist.x = (rc->map.x + 1.0 - rc->pos.x) * rc->absdist.x;
	}
	if (rc->ray_dir.y < 0)
	{
		rc->step.y = -1;
		rc->side_dist.y = (rc->pos.y - rc->map.y) * rc->absdist.y;
	}
	else
	{
		rc->step.y = 1;
		rc->side_dist.y = (rc->map.y + 1.0 - rc->pos.y) * rc->absdist.y;
	}
}

static void	add_check_hit(t_rc *rc, itab map)
{
	while (!rc->is_hit)
	{
		if (rc->side_dist.x < rc->side_dist.y)
		{
			rc->side_dist.x += rc->absdist.x;
			rc->map.x += rc->step.x;
			rc->is_side = false;
		}
		else
		{
			rc->side_dist.y += rc->absdist.y;
			rc->map.y += rc->step.y;
			rc->is_side = true;
		}
		if (map[rc->map.y][rc->map.x] > 0)
			rc->is_hit = true;
	}
}

static void	add_set_draw_area(t_rc *rc, iarr screen,
							itab colors, point *p)
{
	int	current_color;

	if (!rc->is_side)
		rc->pwd = (rc->map.x
			- rc->pos.x + (1 - rc->step.x) / 2) / rc->ray_dir.x;
	else
		rc->pwd = (rc->map.y
			- rc->pos.y + (1 - rc->step.y) / 2) / rc->ray_dir.y;
	rc->hline = (int)(WIN_Y / rc->pwd);
	rc->draw_start = -(rc->hline) / 2 + WIN_Y / 2;
	rc->draw_end = rc->hline / 2 + WIN_Y / 2;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	if (rc->draw_end >= WIN_Y)
		rc->draw_end = WIN_Y - 1;
	current_color = colors[rc->map.y][rc->map.x];
	if (rc->is_side)
		current_color /= 2;
	p->y = rc->draw_start;
	while (p->y <= rc->draw_end)
		screen[(p->y)++ * WIN_X + p->x] = current_color;
}

void		wolf_rendering_rc(t_env *env)
{
	point	p;

	ft_bzero(SPTR, sizeof(int) * WIN_X * WIN_Y);
	p.y = -1;
	while (++(p.y) < WIN_Y && (p.x = -1))
		while (++(p.x) < WIN_X)
			SPTR[p.y * WIN_X + p.x] = (p.y >= WIN_Y / 2)
								? IRGB_GRAY : IRGB_GRAY / 0.5;
	p.x = -1;
	while (++(p.x) < WIN_X)
	{
		*(RC) = (t_rc){{RC->pos.y, RC->pos.x}, {RC->dir.y, RC->dir.x},
		{RC->plane.y, RC->plane.x}, 0, {0, 0}, {0, 0}, {0, 0}, {0, 0},
		0, {0, 0}, false, false, 0, 0, 0};
		RC->xcamera = 2 * p.x / (double)WIN_X - 1;
		RC->ray_dir = (fpoint){RC->dir.y + RC->plane.y * RC->xcamera,
			RC->dir.x + RC->plane.x * RC->xcamera };
		RC->map = (point){(int)RC->pos.y, (int)RC->pos.x};
		RC->absdist = (fpoint){_ABS(1 / RC->ray_dir.y),
			_ABS(1 / RC->ray_dir.x)};
		add_set_diststep(RC);
		add_check_hit(RC, MAP);
		add_set_draw_area(RC, SPTR, MAPC, &p);
	}
	mlx_put_image_to_window(MPTR, WPTR, IPTR, 0, 0);
}
