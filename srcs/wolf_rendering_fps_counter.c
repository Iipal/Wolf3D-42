/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering_fps_counter.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:42:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/07 16:16:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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
	while (++(p.y) < text->h && (p.x = -1) && (tp.x = -1))
	{
		while (++(p.x) < text->w)
			screen[tp.y * WIN_X + ++(tp.x)] = pixels[p.y * text->w + p.x];
		++(tp.y);
	}
}

void	wolf_rendering_fps_counter(t_env *env)
{
	string			data[2];
	SDL_Surface		*text;
	int				i;

	i = -1;
	data[0] = ft_itoa(1.0 / env->fps.time.res_time);
	data[0] = ft_strcat(data[0], " fps");
	data[1] = ft_itoa(env->fps.time.res_time * 1000);
	data[1] = ft_strcat(data[1], " ms");
	while (++i < 2)
	{
		text = wolf_optimize_font_load(data[i], (SDL_Color){127, 255, 0, 0},
			env->sdl->font, env->sdl->win_surface->format);
		add_render_fps(text, env->sdl->win_pixels, i);
		SDL_FreeSurface(text);
	}
	ft_strdel(&(data[0]));
	ft_strdel(&(data[1]));
}
