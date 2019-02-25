/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:03:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/25 15:12:54 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static float	add_fog_freq(int *freq, t_time *time)
{
	const float	freqs[] = {4.2, 4.24, 4.19, 4.21, 4.4, 4.35, 4.31, 4.16};

	if (time->res_time > 0.15)
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

static void		add_draw_torch(t_env *env)
{
	static int	old_torch_frame;
	static int	torch_frame;
	point		p;
	point		tp;

	if (old_torch_frame != FOG.freq)
	{
		torch_frame = ft_rand(MAX_TORCH - 1);
		old_torch_frame = FOG.freq;
	}
	tp.y = -1;
	p.y = TORCH_SHIFT_Y;
	while (++(p.y) < WIN_Y && ++(tp.y) < TORCH->tex[torch_frame].surf->h
		&& (tp.x = -1)
		&& (p.x = TORCH_SHIFT_X))
		while (++(p.x) < WIN_X && ++(tp.x) < TORCH->tex[torch_frame].surf->w)
			if (!(ft_is_one_of_n(TORCH->tex[torch_frame].pixels[
				tp.y * TORCH->tex[torch_frame].surf->w + tp.x],
				2, (long)0xff000000, (long)0x00)))
				SWINP[p.y * WIN_X + p.x] = TORCH->tex[torch_frame].pixels[
					tp.y * TORCH->tex[torch_frame].surf->w + tp.x];
}

static void		add_draw_bonus(t_env *env)
{
	ISRMM ? wolf_draw_minimap(env) : 0;
	ISRF ? add_draw_torch(env) : 0;
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
	SDL_FillRect(SWINS, NULL, IRGB_BLACK);
	(ISRF) ? (FOG.fog_dist = add_fog_freq(&FOG.freq, &TORCH->time)) : 0;
	(!ISRT) ? wolf_fill_floor_if_colored_rc(env->sdl) : 0;
	while (++(p.x) < WIN_X)
	{
		*(RC) = (t_rc){{RC->pos.y, RC->pos.x}, {RC->dir.y, RC->dir.x},
		{RC->plane.y, RC->plane.x}, 0, {0, 0}, {0, 0}, {0, 0}, {0, 0}, 0,
		{0, 0}, false, false, 0, 0, 0};
		RC->xcamera = 2 * p.x / (double)WIN_X - 1;
		RC->raydir = (fpoint){RC->dir.y + RC->plane.y * RC->xcamera,
			RC->dir.x + RC->plane.x * RC->xcamera };
		RC->map = (point){(int)RC->pos.y, (int)RC->pos.x};
		RC->ddist = (fpoint){_ABS(1 / RC->raydir.y), _ABS(1 / RC->raydir.x)};
		wolf_set_diststep(RC);
		wolf_check_hit(RC, MAP);
		wolf_dist_to_wall(RC);
		ISRT ? wolf_render_textured(env, &p) : wolf_render_colored(env, &p);
	}
	add_draw_bonus(env);
	add_fps(&FPS);
	SDL_UpdateWindowSurface(SWIN);
}
