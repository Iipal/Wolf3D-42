/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/05 15:54:01 by tmaluh           ###   ########.fr       */
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
			FREE((*map)->tab[i], free);
		FREE((*map)->tab, free);
	}
	if ((*map)->colors)
	{
		i = -1;
		while (++i < (*map)->size.y)
			FREE((*map)->colors[i], free);
		FREE((*map)->colors, free);
	}
	FREE(*map, free);
}

static void	add_free_surfaces(t_tex **tex, int32_t max)
{
	int32_t	i;

	i = -1;
	while (++i < max)
		FREE((*tex)[i].surf, SDL_FreeSurface);
	FREE(*tex, free);
}

static void	add_free_menu(t_menu **menu)
{
	if ((*menu)->bg)
	{
		FREE((*menu)->bg->surf, SDL_FreeSurface);
		FREE((*menu)->bg, free);
	}
	if ((*menu)->selector)
	{
		FREE((*menu)->selector->surf, SDL_FreeSurface);
		FREE((*menu)->selector, free);
	}
	FREE(*menu, free);
}

static void	add_free_menu_sfx(t_sfx **sfx)
{
	Mix_HaltMusic();
	FREE((*sfx)->start, Mix_FreeChunk);
	FREE((*sfx)->selector, Mix_FreeChunk);
	FREE((*sfx)->selector_err, Mix_FreeChunk);
	FREE((*sfx)->lstep, Mix_FreeChunk);
	FREE((*sfx)->rstep, Mix_FreeChunk);
	FREE((*sfx)->ambient_bg, Mix_FreeMusic);
	FREE((*sfx), free);
	Mix_Quit();
}

void		wolf_free(t_env **env)
{
	IFDO((*env)->map, wolf_free_map(&((*env)->map)));
	if ((*env)->torch && (*env)->torch->tex)
	{
		add_free_surfaces(&((*env)->torch->tex), MAX_TORCH);
		FREE((*env)->torch, free);
	}
	IFDO((*env)->menu, add_free_menu(&((*env)->menu)));
	IFDO((*env)->sfx, add_free_menu_sfx(&((*env)->sfx)));
	if ((*env)->floor_and_sky)
	{
		SDL_FreeSurface((*env)->floor_and_sky->surf);
		FREE((*env)->floor_and_sky, free);
	}
	SDL_FreeSurface((*env)->walls->data->surf);
	FREE((*env)->walls->data, free);
	FREE((*env)->walls->start, free);
	FREE((*env)->walls, free);
	FREE((*env)->isr, free);
	FREE((*env)->rc, free);
	FREE((*env)->sdl->font, TTF_CloseFont);
	FREE((*env)->sdl->win, SDL_DestroyWindow);
	FREE((*env)->sdl, free);
	FREE((*env)->mouse, free);
	FREE(*env, free);
	SDL_Quit();
}
