/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_fog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:10:46 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/25 14:20:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

Uint32	wolf_fog_change(t_clrs *c)
{
	const int	colors[] = {IRGB_WHITE, IRGB_RED, IRGB_ORANGE, IRGB_LIME,
				IRGB_AQUA, IRGB_PURPLE, IRGB_MINT, IRGB_DARK_BLUE, IRGB_BLACK};

	if (++*c >= max_colors)
		*c = white;
	return (colors[*c]);
}

Uint32	wolf_fog(float dist, Uint32 src_color, t_fog *fog)
{
	float		fog_amount;
	Uint32		dest_color;
	SDL_Color	src_rgb;
	SDL_Color	fog_rgb;
	SDL_Color	out_rgb;

	src_rgb = (SDL_Color){src_color >> 16,
		(src_color >> 8) & 0xff, src_color & 0xff, 0};
	fog_rgb = (SDL_Color){fog->fog_color >> 16,
		(fog->fog_color >> 8) & 0xff, fog->fog_color & 0xff, 0};
	dest_color = src_color;
	if (dist >= fog->fog_dist)
		fog_amount = 1.0;
	else
		fog_amount = dist / fog->fog_dist;
	if (fog_amount <= 1.00f && fog_amount > 0.00f)
	{
		out_rgb = (SDL_Color){
			(1.0 - fog_amount) * src_rgb.r + fog_amount * fog_rgb.r,
			(1.0 - fog_amount) * src_rgb.g + fog_amount * fog_rgb.g,
			(1.0 - fog_amount) * src_rgb.b + fog_amount * fog_rgb.b, 0};
		dest_color = (out_rgb.r << 16 | out_rgb.g << 8 | out_rgb.b);
	}
	return (dest_color);
}
