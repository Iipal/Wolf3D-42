/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/15 22:27:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wolf_free_map(t_map **map)
{
	int	i;

	if (*map)
	{
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
}

void	wolf_free(t_env **env)
{
	if ((*env)->map != NULL)
		wolf_free_map(&((*env)->map));
	_FREE((*env)->isr, free);
	_FREE((*env)->rc, free);
	_FREE((*env)->mouse, free);
	_FREE((*env)->xpm, free);
	SDL_DestroyWindow((*env)->sdl->win);
	SDL_Quit();
	_FREE((*env)->sdl, free);
	_FREE(*env, free);
}
