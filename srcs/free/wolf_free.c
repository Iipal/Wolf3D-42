/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 12:39:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		wolf_free_map(t_map **map)
{
	int32_t	i;

	if ((*map)->tab)
	{
		i = -1;
		while (++i < (*map)->size.y)
			_FREE((*map)->tab[i], free);
		_FREE((*map)->tab, free);
	}
	if ((*map)->colors)
	{
		i = -1;
		while (++i < (*map)->size.y)
			_FREE((*map)->colors[i], free);
		_FREE((*map)->colors, free);
	}
	_FREE(*map, free);
}

static void	add_free_surfaces(t_tex **tex, int32_t max)
{
	int32_t	i;

	i = -1;
	while (++i < max)
		_FREE((*tex)[i].surf, SDL_FreeSurface);
	_FREE(*tex, free);
}

static void	add_free_menu(t_menu **menu)
{
	if ((*menu)->bg)
	{
		_FREE((*menu)->bg->surf, SDL_FreeSurface);
		_FREE((*menu)->bg, free);
	}
	if ((*menu)->selector)
	{
		_FREE((*menu)->selector->surf, SDL_FreeSurface);
		_FREE((*menu)->selector, free);
	}
	_FREE(*menu, free);
}

static void	add_free_menu_sfx(t_sfx **sfx)
{
	_FREE((*sfx)->start, Mix_FreeChunk);
	_FREE((*sfx)->selector, Mix_FreeChunk);
	_FREE((*sfx)->selector_err, Mix_FreeChunk);
	_FREE((*sfx)->lstep, Mix_FreeChunk);
	_FREE((*sfx)->rstep, Mix_FreeChunk);
	Mix_HaltMusic();
	_FREE((*sfx)->ambient_bg, Mix_FreeMusic);
	_FREE((*sfx), free);
	Mix_Quit();
}

void		wolf_free(t_env **env)
{
	((*env)->map) ? wolf_free_map(&((*env)->map)) : 0;
	if ((*env)->torch && (*env)->torch->tex)
	{
		add_free_surfaces(&((*env)->torch->tex), MAX_TORCH);
		_FREE((*env)->torch, free);
	}
	((*env)->menu) ? add_free_menu(&((*env)->menu)) : 0;
	((*env)->sfx) ? add_free_menu_sfx(&((*env)->sfx)) : 0;
	if ((*env)->floor_and_sky)
	{
		SDL_FreeSurface((*env)->floor_and_sky->surf);
		_FREE((*env)->floor_and_sky, free);
	}
	SDL_FreeSurface((*env)->walls->data->surf);
	_FREE((*env)->walls->data, free);
	_FREE((*env)->walls->start, free);
	_FREE((*env)->walls, free);
	_FREE((*env)->isr, free);
	_FREE((*env)->rc, free);
	_FREE((*env)->sdl->font, TTF_CloseFont);
	_FREE((*env)->sdl->win, SDL_DestroyWindow);
	_FREE((*env)->sdl, free);
	_FREE((*env)->mouse, free);
	_FREE(*env, free);
	SDL_Quit();
}
