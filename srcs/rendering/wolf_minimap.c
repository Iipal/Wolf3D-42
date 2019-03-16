/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 22:33:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/16 22:08:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	add_rendering_square(t_env *env, int size, fpoint pos, int color)
{
	point	p;
	point	exep;
	int		xstart;

	xstart = size * 2 + size * pos.x;
	p.y = size * 2 + size * pos.y;
	exep = (point){size * 2 + (size * (pos.y + 1)),
			size * 2 + (size * (pos.x + 1))};
	while (p.y < exep.y)
	{
		p.x = xstart;
		while (p.x < exep.x)
			SWINP[p.y * WIN_X + (p.x)++] = color;
		++(p.y);
	}
}

static void	add_rendering_ray(t_env *env, int size, fpoint p)
{
	while (wolf_is_tile(env->map, p) && !env->map->tab[(int)p.y][(int)p.x])
		p = (fpoint) {p.y + RC->dir.y * MMAP_PRECISION,
			p.x + RC->dir.x * MMAP_PRECISION};
	add_rendering_square(env, size, p, IRGB_MAP_RAY);
}

void		wolf_rendering_minimap(t_env *env)
{
	fpoint	p;
	int		size;

	p.y = -1;
	size = WIN_X / 10 / env->map->xsize;
	while (++(p.y) < env->map->ysize && (p.x = -1))
		while (++(p.x) < env->map->xsize)
			if (!wolf_is_tile(env->map, (fpoint){p.y, p.x}))
				add_rendering_square(env, size, p, IRGB_MAP_BG);
	p = (fpoint){RC->pos.y, RC->pos.x};
	add_rendering_square(env, size, p, IRGB_MAP_POS);
	add_rendering_ray(env, size, p);
}
