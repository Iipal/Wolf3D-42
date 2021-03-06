/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:03:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/11 22:36:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_rendering(t_env *env)
{
	SDL_FillRect(env->sdl->win_surface, NULL, RGB_BLACK);
	wolf_raycaster(env);
	if (env->isr->is_render_fog)
	{
		env->fog.fog_dist = wolf_fog_freq(&env->fog.freq, &env->torch->delta,
											env->fps.time.res);
		wolf_rendering_torch(env->torch, env->sdl->win_pixels, env->fog.freq);
	}
	IFDO(env->isr->is_render_minimap, wolf_rendering_minimap(env));
	if (env->isr->is_render_blur)
		wolf_blur((point){env->bsize, env->bsize}, env->sdl->win_pixels, 1, 0);
	wolf_fps(&(env->fps));
	IFDO(env->isr->is_render_fps, wolf_rendering_fps_counter(env));
	SDL_UpdateWindowSurface(env->sdl->win);
}
