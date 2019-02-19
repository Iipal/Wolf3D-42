/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/19 11:25:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		wolf_free_map(t_map **map)
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

static void	add_free_textures(t_tex **tex)
{
	int	i;

	i = -1;
	while (++i < MAX_TEXTURES + 2)
		_FREE((*tex)[i].surf, SDL_FreeSurface);
	_FREE(*tex, free);
}

static void	add_free_torch(t_tex **tex)
{
	int	i;

	i = -1;
	while (++i < MAX_TORCH)
		_FREE((*tex)[i].surf, SDL_FreeSurface);
	_FREE(*tex, free);
}

void		wolf_free(t_env **env)
{
	if ((*env)->map)
		wolf_free_map(&((*env)->map));
	if ((*env)->textures)
		add_free_textures(&((*env)->textures));
	if ((*env)->torch)
		add_free_torch(&((*env)->torch));
	_FREE((*env)->isr, free);
	_FREE((*env)->rc, free);
	_FREE((*env)->sdl, free);
	_FREE((*env)->mouse, free);
	_FREE(*env, free);
}
