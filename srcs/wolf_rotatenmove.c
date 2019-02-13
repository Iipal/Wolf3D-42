/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rotatenmove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 01:03:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/13 22:29:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

bool		wolf_is_tile(t_map *map, fpoint pos)
{
	if (pos.x < 0 || pos.y < 0
	|| pos.x > map->xsize - 1
	|| pos.y > map->ysize - 1)
		return (false);
	else if (map->tab[(int)pos.y][(int)pos.x])
		return (false);
	return (true);
}

void		wolf_move(t_env *env, float dist)
{
	if (wolf_is_tile(env->map,
		(fpoint){RC->pos.y, RC->pos.x + dist * RC->dir.x}))
		RC->pos.x += dist * RC->dir.x;
	if (wolf_is_tile(env->map,
		(fpoint){RC->pos.y + dist * RC->dir.y, RC->pos.x}))
		RC->pos.y += dist * RC->dir.y;
}

static void	add_rotate(fpoint *fp, float angle)
{
	float	xtemp;
	float	xcos;
	float	xsin;

	xtemp = fp->x;
	xcos = cos(angle);
	xsin = sin(angle);
	fp->x = fp->x * xcos - fp->y * xsin;
	fp->y = xtemp * xsin + fp->y * xcos;
}

void		wolf_rotate(t_rc *rc, float angle)
{
	add_rotate(&(rc->plane), angle);
	add_rotate(&(rc->dir), angle);
}
