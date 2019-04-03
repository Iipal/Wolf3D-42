/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_fps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:42:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 00:20:26 by tmaluh           ###   ########.fr       */
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
	while (++(p.y) < text->h && (p.x = -1)
		&& (tp.x = -1))
	{
		while (++(p.x) < text->w)
			screen[tp.y * WIN_X + ++(tp.x)] = pixels[p.y * text->w + p.x];
		++(tp.y);
	}
}

void		wolf_rendering_fps_counter(t_env *env)
{
	const string	data_info[] = {" fps", " ms"};
	string			data[2];
	string			temp[2];
	SDL_Surface		*text;
	int8_t			i;

	i = -1;
	while (++i < 2)
	{
		data[i] = i ? ft_itoa(env->fps.time.res * 1000)
			: ft_itoa(1.0 / env->fps.time.res);
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

void		wolf_fps(t_fps *fps)
{
	fps->time.old = fps->time.current;
	fps->time.current = SDL_GetTicks();
	fps->time.res = (fps->time.current - fps->time.old) / 1000.0;
	fps->move = fps->time.res * MOVE_INC;
	fps->rot = fps->time.res * ROT_INC;
}
