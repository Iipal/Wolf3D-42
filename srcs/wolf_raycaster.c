/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:13:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/13 13:12:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wolf_set_diststep(t_rc *rc)
{
	if (rc->raydir.x < 0)
	{
		rc->step.x = -1;
		rc->side_dist.x = (rc->pos.x - rc->map.x) * rc->absdist.x;
	}
	else
	{
		rc->step.x = 1;
		rc->side_dist.x = (rc->map.x + 1.0 - rc->pos.x) * rc->absdist.x;
	}
	if (rc->raydir.y < 0)
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

void	wolf_check_hit(t_rc *rc, itab map)
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

void	wolf_set_draw_area(t_rc *rc)
{
	if (!rc->is_side)
		rc->pwd = (rc->map.x
			- rc->pos.x + (1 - rc->step.x) / 2) / rc->raydir.x;
	else
		rc->pwd = (rc->map.y
			- rc->pos.y + (1 - rc->step.y) / 2) / rc->raydir.y;
	rc->hline = (int)(WIN_Y / rc->pwd);
	rc->draw_start = -(rc->hline) / 2 + WIN_Y / 2;
	rc->draw_end = rc->hline / 2 + WIN_Y / 2;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	if (rc->draw_end >= WIN_Y)
		rc->draw_end = WIN_Y - 1;
}
