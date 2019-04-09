/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_fps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:42:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 20:19:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	add_render_fps(SDL_Surface *text, iarr screen, bool pos)
{
	point	tp;
	point	p;
	iarr	pixels;

	pixels = text->pixels;
	p.y = -1;
	tp.y = 0;
	if (pos)
		tp.y = 20;
	while (text->h > ++(p.y) && (p.x = -1)
	&& (tp.x = -1))
	{
		while (text->w > ++(p.x))
			screen[tp.y * WIN_X + ++(tp.x)] = pixels[p.y * text->w + p.x];
		++(tp.y);
	}
}

static void	add_fps_prepare_and_draw(float dfps, float dms, t_env *env)
{
	const string	data_info[] = {" fps", " ms"};
	string			data[2];
	string			temp[2];
	SDL_Surface		*text;
	int8_t			i;

	i = -1;
	while (2 > ++i)
	{
		data[i] = (i ? ft_itoa(dms) : ft_itoa(dfps));
		temp[i] = data[i];
		data[i] = ft_strjoin(data[i], data_info[i]);
		text = wolf_optimize_font_load(data[i], (SDL_Color){127, 255, 0, 0},
			env->sdl->font, env->sdl->win_surface->format);
		ft_strdel(&(temp[i]));
		ft_strdel(&(data[i]));
		add_render_fps(text, env->sdl->win_pixels, i);
		SDL_FreeSurface(text);
	}
}

void		wolf_rendering_fps_counter(t_env *env)
{
	static float	delta;
	static float	delta_fps;
	static float	delta_ms;

	(delta > REFRESH_FPS_COUNTER) ? (delta = 0) : 0;
	if (.0f == delta)
	{
		delta_fps = 1.0 / env->fps.time.res;
		delta_ms = env->fps.time.res * 1000;
	}
	add_fps_prepare_and_draw(delta_fps, delta_ms, env);
	delta += env->fps.time.res;
}

void		wolf_fps(t_fps *fps)
{
	fps->time.old = fps->time.current;
	fps->time.current = SDL_GetTicks();
	fps->time.res = (fps->time.current - fps->time.old) / 1000.0;
	fps->move = fps->time.res * MOVE_INC;
	fps->rot = fps->time.res * ROT_INC;
}
