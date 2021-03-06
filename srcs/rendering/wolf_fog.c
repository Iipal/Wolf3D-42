/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_fog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:10:46 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/11 22:22:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

Uint32	wolf_fog_change(t_colors *c)
{
	const int32_t	colors[] = {RGB_WHITE, RGB_RED, RGB_ORANGE, RGB_LIME,
				RGB_AQUA, RGB_PURPLE, RGB_MINT, RGB_DARK_BLUE, RGB_BLACK};

	IFDO(++(*c) >= max_colors, *c = white);
	return (colors[*c]);
}

float	wolf_fog_freq(uint8_t *freq, float *delta, float game_delta)
{
	const float	freqs[] = {4.2f, 4.25f, 4.13f, 4.17f, 4.22f, 4.3f, 4.1f, 4.19f};

	if (REFRESH_TORCH_FOG_FREQ < *delta)
	{
		*delta = 0;
		*freq = ft_rand((sizeof(freqs) / sizeof(*freqs)) - 1);
	}
	else
		*delta += game_delta;
	return (freqs[(*freq)]);
}

Uint32	wolf_fog(float dist_to_obj, Uint32 src_color, t_fog *fog)
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
	if (fog->fog_dist <= dist_to_obj)
		fog_amount = 1.0;
	else
		fog_amount = dist_to_obj / fog->fog_dist;
	if (1.0f >= fog_amount && .0f < fog_amount)
	{
		out_rgb = (SDL_Color){
			(1.0 - fog_amount) * src_rgb.r + fog_amount * fog_rgb.r,
			(1.0 - fog_amount) * src_rgb.g + fog_amount * fog_rgb.g,
			(1.0 - fog_amount) * src_rgb.b + fog_amount * fog_rgb.b, 0};
		dest_color = (out_rgb.r << 16 | out_rgb.g << 8 | out_rgb.b);
	}
	return (dest_color);
}
