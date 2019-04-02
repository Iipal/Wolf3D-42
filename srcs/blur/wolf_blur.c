/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_blur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:47:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/02 20:18:29 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	add_fill_blur_mask(float *bmap, point size, float value)
{
	point	p;
	int		max_fill_range;
	int		fill_range;
	int		fill_cells;

	p.y = -1;
	fill_cells = 0;
	max_fill_range = (size.x % 2) ? 1 : 2;
	while (++(p.y) < size.y)
	{
		if (max_fill_range > size.x)
			max_fill_range = size.x;
		fill_cells += max_fill_range;
		p.x = (size.x - max_fill_range) / 2;
		fill_range = size.x - (p.x * 2);
		while (fill_range--)
			bmap[p.y * size.x + (p.x)++] = value;
		if (p.y < size.y / 2)
			max_fill_range += 2;
		else
			max_fill_range -= 2;
	}
	return (fill_cells);
}

static void	add_blur_proccesing(t_bhelp b)
{
	FColor		fc;
	SDL_Color	srcc;
	point		i;
	point		f;
	SDL_Color	outc;

	f.y = -1;
	fc = (FColor){0.0, 0.0, 0.0};
	while (++(f.y) < b.size.y && (f.x = -1))
		while (++(f.x) < b.size.x)
		{
			i.x = (b.p->x - b.size.x / 2 + f.x + WIN_X) % WIN_X;
			i.y = (b.p->y - b.size.y / 2 + f.y + WIN_Y) % WIN_Y;
			srcc.r = b.src[i.y * WIN_X + i.x] >> 16;
			srcc.g = (b.src[i.y * WIN_X + i.x] >> 8) & 0xff;
			srcc.b = b.src[i.y * WIN_X + i.x] & 0xff;
			fc.r += srcc.r * b.bmap[f.y * b.size.x + f.x];
			fc.g += srcc.g * b.bmap[f.y * b.size.x + f.x];
			fc.b += srcc.b * b.bmap[f.y * b.size.x + f.x];
		}
	outc.r = MIN(MAX((int)(b.factor * fc.r + b.dimm), 0), 255);
	outc.g = MIN(MAX((int)(b.factor * fc.g + b.dimm), 0), 255);
	outc.b = MIN(MAX((int)(b.factor * fc.b + b.dimm), 0), 255);
	b.src[b.p->y * WIN_X + b.p->x] = (outc.r << 16 | outc.g << 8 | outc.b);
}

void		wolf_blur(point size, iarr src, float value, float dimmed)
{
	float		bmap[size.y][size.x];
	point		p;
	float		factor;

	ft_bzero((float**)bmap, sizeof(float) * (size.y * size.x));
	factor = 1.0 / add_fill_blur_mask((float*)&(bmap[0][0]), size, value);
	p.y = -1;
	while (++(p.y) < WIN_Y && (p.x = -1))
		while (++(p.x) < WIN_X)
			add_blur_proccesing((t_bhelp){
				&p, src, (float*)&(bmap[0][0]), dimmed, factor, size});
}
