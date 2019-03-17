/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_sdl_optimizing_load.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 09:51:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/16 21:26:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Surface	*wolf_optimize_surf_load(string bmp_path,
							const SDL_PixelFormat *format)
{
	SDL_Surface	*optimize_out;
	SDL_Surface	*temp_load;

	optimize_out = NULL;
	_NOTIS(SDL_GetError(),
		temp_load = SDL_LoadBMP(bmp_path), exit(EXIT_FAILURE), NULL);
	_NOTIS(SDL_GetError(),
		optimize_out = SDL_ConvertSurface(temp_load, format, 0),
		exit(EXIT_FAILURE), NULL);
	SDL_FreeSurface(temp_load);
	return (optimize_out);
}

SDL_Surface	*wolf_optimize_font_load(string text, SDL_Color text_color,
	TTF_Font *font, SDL_PixelFormat *format)
{
	SDL_Surface	*optimize_out;
	SDL_Surface	*temp_load;

	_NOTIS(TTF_GetError(),
		temp_load = TTF_RenderText_Solid(font, text, text_color),
		exit(EXIT_FAILURE), NULL);
	_NOTIS(SDL_GetError(),
		optimize_out = SDL_ConvertSurface(temp_load, format, 0),
		exit(EXIT_FAILURE), NULL);
	SDL_FreeSurface(temp_load);
	return (optimize_out);
}
