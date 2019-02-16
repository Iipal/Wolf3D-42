/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_fog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:10:46 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/16 23:00:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

Uint32	wolf_fog(double dist, Uint32 src_color)
{
	float		fog_amount;
	Uint32		dest_color;
	SDL_Color	src_rgb = {src_color >> 16, (src_color >> 8) & 0xff, src_color & 0xff, 0};
	SDL_Color	out_rgb;

	dest_color = src_color;
 	if (dist >= MAX_FOG_DIST)
		fog_amount = 1.0;
	else
		fog_amount = dist / MAX_FOG_DIST;
	if (fog_amount <= 1.00f && fog_amount > 0.00f)
	{
		out_rgb = (SDL_Color){
			(1.0 - fog_amount) * src_rgb.r + 0,
			(1.0 - fog_amount) * src_rgb.g + 0,
			(1.0 - fog_amount) * src_rgb.b + 0, 0};
		dest_color = (out_rgb.r << 16 | out_rgb.g << 8 | out_rgb.b);
	}
	return (dest_color);
}
