/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_blur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:47:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/17 22:01:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	add_fill_blur_mask(float *bmap, point size, float value)
{
	point	p;
	int		max_fill_range;
	int		fill_range;

	p.y = -1;
	max_fill_range = (size.x % 2) ? 1 : 2;
	while (++(p.y) < size.y)
	{
		if (max_fill_range > size.x)
			max_fill_range = size.x;
		p.x = (size.x - max_fill_range) / 2;
		fill_range = size.x - (p.x * 2);
		while (fill_range--)
			bmap[p.y * size.x + (p.x)++] = value;
		if (p.y < size.y / 2)
			max_fill_range += 2;
		else
			max_fill_range -= 2;
	}
}

void		wolf_blur(point size, iarr src, float value)
{
	float	bmap[size.y][size.x];

	ft_bzero((float**)bmap, sizeof(float) * (size.y * size.x));
	add_fill_blur_mask((float*)&(bmap[0][0]), size, value);
	if (src)
	{
	}
}
