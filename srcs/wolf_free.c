/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/09 11:54:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wolf_free_matrix(t_matrix **m, int y)
{
	int	i;

	i = -1;
	if (m)
	{
		while (++i < y)
			m[i] ? free(m[i]) : 0;
		free(m);
		m = NULL;
	}
}

void	wolf_free_map(t_map *map)
{
	int	i;

	i = -1;
	if (map)
	{
		if (map->tab)
		{
			i = -1;
			while (++i < map->ysize)
				if (map->tab[i] != NULL)
					free(map->tab[i]);
			free(map->tab);
		}
		if (map->colors)
		{
			i = -1;
			while (++i < map->ysize)
				if (map->colors[i] != NULL)
					free(map->colors[i]);
			free(map->colors);
		}
		free(map);
		map = NULL;
	}
}

void	wolf_free(t_env *env)
{
	IPTR ? mlx_destroy_image(MPTR, IPTR) : 0;
	WPTR ? mlx_destroy_window(MPTR, WPTR) : 0;
	env->mlx ? free(env->mlx) : NULL;
	env->raw ? wolf_free_map(env->raw) : 0;
	env->map ? free(env->map) : NULL;
	env->isr ? free(env->isr) : NULL;
	env ? free(env) : NULL;
}
