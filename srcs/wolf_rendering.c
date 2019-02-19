/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:03:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/19 15:21:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static float	add_fog_freq(int *freq)
{
	const float	freqs[] = {4.2, 4.22, 4.23, 4.21, 4.4, 4.35, 4.31, 4.16,
	4.15, 4.14, 4.32, 4.31, 4.30, 4.29, 4.32, 4.39, 4.40, 4.45, 4.39, 4.15,
	4.30, 4.25, 4.24, 4.21, 4.1, 4.2, 4.24, 4.6, 4.4, 4.45, 4.1};

	if ((ull)(*freq) > (sizeof(freqs) / sizeof(*freqs)) - 1)
		*freq = 0;
	return (freqs[(*freq)++]);
}

static void		add_fps(t_fps *fps)
{
	fps->told = fps->time;
	fps->time = SDL_GetTicks();
	fps->tframe = (fps->time - fps->told) / 1000.0;
	fps->move = fps->tframe * MOVE_INC;
	fps->rot = fps->tframe * ROT_INC;
}

static void		add_draw_torch(t_env *env)
{
	static int	torch_frame;
	point		p;
	point		tp;

	if (!((RC->freq + 1) % MAX_TORCH))
		torch_frame = ft_rand(MAX_TORCH - 1);
	tp.y = -1;
	p.y = TORCH_SHIFT_Y;
	while (++(p.y) && ++(tp.y) < TORCH[torch_frame].surf->h && (tp.x = -1)
		&& (p.x = TORCH_SHIFT_X))
		while (++(p.x) && ++(tp.x) < TORCH[torch_frame].surf->w)
			if (!(TORCH[torch_frame].pixels[
				tp.y * TORCH[torch_frame].surf->w + tp.x] == 0xff000000)
				&& _ISSCREEN(p.y, p.x))
				SWINP[p.y * WIN_X + p.x] = TORCH[torch_frame].pixels[
					tp.y * TORCH[torch_frame].surf->w + tp.x];
}

void			wolf_rendering_rc(t_env *env)
{
	point			p;

	p.x = -1;
	SDL_FillRect(SWINS, NULL, IRGB_BLACK);
	(ISRF) ? (RC->fog_dist = add_fog_freq(&RC->freq)) : 0;
	(!ISRT) ? wolf_fill_floor_if_colored_rc(env->sdl) : 0;
	while (++(p.x) < WIN_X)
	{
		*(RC) = (t_rc){{RC->pos.y, RC->pos.x}, {RC->dir.y, RC->dir.x},
	{RC->plane.y, RC->plane.x}, 0, {0, 0}, {0, 0}, {0, 0}, {0, 0}, 0, {0, 0},
	false, false, 0, 0, 0, RC->clr, RC->fog_color, RC->fog_dist, RC->freq};
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
	ISRMM ? wolf_draw_minimap(env) : 0;
	ISRF ? add_draw_torch(env) : 0;
	SDL_UpdateWindowSurface(SWIN);
	add_fps(&FPS);
}
