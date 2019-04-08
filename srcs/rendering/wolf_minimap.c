/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 22:33:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/08 14:29:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	add_rendering_square(t_env *env, int32_t size,
								fpoint pos, int32_t color)
{
	point	p;
	point	exep;
	int32_t	xstart;

	xstart = size * 2 + size * pos.x;
	p.y = (size * 2 + size * pos.y) - 1;
	exep = (point){size * 2 + (size * (pos.y + 1)),
			size * 2 + (size * (pos.x + 1))};
	while (++(p.y) < exep.y && ((p.x = xstart) ? p.x : !p.x))
		while (p.x < exep.x)
			SWINP[p.y * WIN_X + (p.x)++] = color;
}

static void	add_rendering_ray(t_env *env, int32_t size, fpoint p)
{
	while (wolf_is_tile(env->map, p)
	&& !env->map->tab[(int32_t)p.y][(int32_t)p.x])
		p = (fpoint) {p.y + RC->dir.y * MMAP_PRECISION,
			p.x + RC->dir.x * MMAP_PRECISION};
	add_rendering_square(env, size, p, RGB_MAP_RAY);
}

void		wolf_rendering_minimap(t_env *env)
{
	fpoint	p;
	int32_t	size;

	p.y = -1;
	size = WIN_X / 10 / env->map->size.x;
	while (++(p.y) < env->map->size.y && (p.x = -1))
		while (++(p.x) < env->map->size.x)
			if (!wolf_is_tile(env->map, (fpoint){p.y, p.x}))
				add_rendering_square(env, size, p, RGB_MAP_BG);
	p = (fpoint){RC->pos.y, RC->pos.x};
	add_rendering_square(env, size, p, RGB_MAP_POS);
	add_rendering_ray(env, size, p);
}
