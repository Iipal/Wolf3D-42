/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_fog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:10:46 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/16 22:08:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

Uint32	wolf_fog_change(t_colors *c)
{
	const int	colors[] = {IRGB_WHITE, IRGB_RED, IRGB_ORANGE, IRGB_LIME,
				IRGB_AQUA, IRGB_PURPLE, IRGB_MINT, IRGB_DARK_BLUE, IRGB_BLACK};

	if (++*c >= max_colors)
		*c = white;
	return (colors[*c]);
}

float	wolf_fog_freq(int *freq, t_time *time)
{
	const float	freqs[] = {4.2, 4.25, 4.15, 4.17, 4.22, 4.3, 4.1, 4.16};

	if (time->res > REFRESH_TORCH_FOG_FREQ)
	{
		time->res = 0;
		*freq = ft_rand((sizeof(freqs) / sizeof(*freqs)) - 1);
	}
	else
	{
		time->old = time->current;
		time->current = SDL_GetTicks();
		time->res += (time->current - time->old) / 1000.0;
	}
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
	if (dist_to_obj >= fog->fog_dist)
		fog_amount = 1.0;
	else
		fog_amount = dist_to_obj / fog->fog_dist;
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
