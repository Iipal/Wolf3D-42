/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:03:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/07 15:00:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static float	add_fog_freq(int *freq, t_time *time)
{
	const float	freqs[] = {4.2, 4.25, 4.15, 4.17, 4.22, 4.3, 4.1, 4.16};

	if (time->res_time > REFRESH_TORCH_FOG_FREQ)
	{
		time->res_time = 0;
		*freq = ft_rand((sizeof(freqs) / sizeof(*freqs)) - 1);
	}
	else
	{
		time->old_time = time->current_time;
		time->current_time = SDL_GetTicks();
		time->res_time += (time->current_time - time->old_time) / 1000.0;
	}
	return (freqs[(*freq)]);
}

static void		add_rendering_torch(t_env *env)
{
	static int		old_torch_frame;
	static int		torch_frame;
	const fpoint	torch_shift = {TORCH_SHIFT_Y, TORCH_SHIFT_X};
	point			p;
	point			tp;

	if (old_torch_frame != FOG.freq)
	{
		torch_frame = ft_rand(MAX_TORCH - 1);
		old_torch_frame = FOG.freq;
	}
	tp.y = -1;
	p.y = torch_shift.y;
	while (++(p.y) < WIN_Y && ++(tp.y) < env->torch->tex[torch_frame].surf->h
		&& (tp.x = -1)
		&& (p.x = torch_shift.x))
		while (++(p.x) < WIN_X
			&& ++(tp.x) < env->torch->tex[torch_frame].surf->w)
			if (!(ft_is_one_of_n(env->torch->tex[torch_frame].pixels[
				tp.y * env->torch->tex[torch_frame].surf->w + tp.x],
				2, (long)0xff000000, (long)0x00)))
				env->sdl->win_pixels[p.y * WIN_X + p.x] =
					env->torch->tex[torch_frame].pixels[tp.y * env->torch->tex[
						torch_frame].surf->w + tp.x];
}

static void		add_rendering_bonus(t_env *env)
{
	env->isr->is_render_minimap ? wolf_rendering_minimap(env) : 0;
	env->isr->is_render_fog ? add_rendering_torch(env) : 0;
}

static void		add_fps(t_fps *fps)
{
	fps->time.old_time = fps->time.current_time;
	fps->time.current_time = SDL_GetTicks();
	fps->time.res_time = (fps->time.current_time - fps->time.old_time) / 1000.0;
	fps->move = fps->time.res_time * MOVE_INC;
	fps->rot = fps->time.res_time * ROT_INC;
}

void			wolf_rendering_rc(t_env *env)
{
	point			p;

	p.x = -1;
	SDL_FillRect(env->sdl->win_surface, NULL, IRGB_BLACK);
	(ISRF) ? (FOG.fog_dist = add_fog_freq(&FOG.freq, &(env->torch->time))) : 0;
	(!env->isr->is_textured) ? wolf_fill_floor_if_colored_rc(env->sdl) : 0;
	while (++(p.x) < WIN_X)
	{
		*(env->rc) = (t_rc){{RC->pos.y, RC->pos.x}, {RC->dir.y, RC->dir.x},
		{RC->plane.y, RC->plane.x}, 0, {0, 0}, {0, 0}, {0, 0}, {0, 0}, 0,
		{0, 0}, false, false, 0, 0, 0};
		RC->xcamera = 2 * p.x / (double)WIN_X - 1;
		env->rc->raydir = (fpoint){RC->dir.y + RC->plane.y * RC->xcamera,
			env->rc->dir.x + env->rc->plane.x * env->rc->xcamera };
		env->rc->map = (point){(int)env->rc->pos.y, (int)env->rc->pos.x};
		RC->ddist = (fpoint){_ABS(1 / RC->raydir.y), _ABS(1 / RC->raydir.x)};
		wolf_set_diststep(env->rc);
		wolf_check_hit(env->rc, env->map->tab);
		wolf_dist_to_wall(env->rc);
		ISRT ? wolf_render_textured(env, &p) : wolf_render_colored(env, &p);
	}
	add_rendering_bonus(env);
	add_fps(&(env->fps));
	env->isr->is_render_fps ? wolf_rendering_fps_counter(env) : 0;
	SDL_UpdateWindowSurface(env->sdl->win);
}
