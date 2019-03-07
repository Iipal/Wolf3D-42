/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/07 12:18:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		wolf_free_map(t_map **map)
{
	int	i;

	if ((*map)->tab)
	{
		i = -1;
		while (++i < (*map)->ysize)
			if ((*map)->tab[i] != NULL)
				_FREE((*map)->tab[i], free);
		_FREE((*map)->tab, free);
	}
	if ((*map)->colors)
	{
		i = -1;
		while (++i < (*map)->ysize)
			if ((*map)->colors[i] != NULL)
				_FREE((*map)->colors[i], free);
		_FREE((*map)->colors, free);
	}
	_FREE(*map, free);
}

static void	add_free_surfaces(t_tex **tex, int max)
{
	int	i;

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
	_FREE((*sfx)->exit, Mix_FreeChunk);
	_FREE((*sfx)->selector, Mix_FreeChunk);
	_FREE((*sfx)->selector_err, Mix_FreeChunk);
	_FREE((*sfx)->exit, Mix_FreeChunk);
	_FREE((*sfx)->lstep, Mix_FreeChunk);
	_FREE((*sfx)->rstep, Mix_FreeChunk);
	Mix_HaltMusic();
	_FREE((*sfx)->ambient_bg, Mix_FreeMusic);
	_FREE((*sfx), free);
}

void		wolf_free(t_env **env)
{
	if ((*env)->map)
		wolf_free_map(&((*env)->map));
	if ((*env)->textures)
		add_free_surfaces(&((*env)->textures), MAX_TEXTURES + 2);
	if ((*env)->torch)
	{
		add_free_surfaces(&((*env)->torch->tex), MAX_TORCH);
		_FREE((*env)->torch, free);
	}
	if ((*env)->menu)
		add_free_menu(&((*env)->menu));
	if ((*env)->sfx)
		add_free_menu_sfx(&((*env)->sfx));
	_FREE((*env)->isr, free);
	_FREE((*env)->rc, free);
	_FREE((*env)->sdl, free);
	_FREE((*env)->mouse, free);
	_FREE(*env, free);
	Mix_Quit();
	SDL_Quit();
	exit(EXIT_SUCCESS);
}
