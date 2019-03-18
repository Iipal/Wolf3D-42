/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:03:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/18 23:27:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		add_fps(t_fps *fps)
{
	fps->time.old = fps->time.current;
	fps->time.current = SDL_GetTicks();
	fps->time.res = (fps->time.current - fps->time.old) / 1000.0;
	fps->move = fps->time.res * MOVE_INC;
	fps->rot = fps->time.res * ROT_INC;
}

void			wolf_rendering(t_env *env)
{
	SDL_FillRect(env->sdl->win_surface, NULL, IRGB_BLACK);
	wolf_raycaster(env);
	if (env->isr->is_render_fog)
	{
		env->fog.fog_dist = wolf_fog_freq(&env->fog.freq, &env->torch->time);
		if (!env->isr->is_render_weapon)
			wolf_rendering_torch(env);
	}
	if (env->isr->is_render_weapon)
		wolf_rendering_weapons(env);
	if (env->isr->is_render_minimap)
		wolf_rendering_minimap(env);
	add_fps(&(env->fps));
	if (env->isr->is_render_fps)
		wolf_rendering_fps_counter(env);
	if (env->isr->is_render_blur)
		wolf_blur((point){env->bsize, env->bsize}, env->sdl->win_pixels, 1, 0);
	SDL_UpdateWindowSurface(env->sdl->win);
}
