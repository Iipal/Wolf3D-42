/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rotatenmove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 01:03:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 23:23:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

bool		wolf_is_tile(t_map *map, fpoint pos)
{
	if (0 > pos.x || 0 > pos.y
	|| map->size.x - 1 < pos.x
	|| map->size.y - 1 < pos.y)
		return (false);
	else if (map->tab[(int)pos.y][(int)pos.x])
		return (false);
	return (true);
}

void		wolf_move(t_env *env, float dist)
{
	if (wolf_is_tile(env->map,
		(fpoint){env->rc->pos.y, env->rc->pos.x + (dist * 2) * env->rc->dir.x}))
		env->rc->pos.x += dist * env->rc->dir.x;
	if (wolf_is_tile(env->map,
		(fpoint){env->rc->pos.y + (dist * 2) * env->rc->dir.y, env->rc->pos.x}))
		env->rc->pos.y += dist * env->rc->dir.y;
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
