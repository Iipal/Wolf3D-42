/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/09 13:25:33 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wolf_free_matrix(t_matrix ***m, int y)
{
	int	i;

	i = -1;
	if (*m)
	{
		while (++i < y)
			_FREE((*m)[i], free);
		_FREE(*m, free);
	}
}

void	wolf_free_map(t_map **map)
{
	int	i;

	i = -1;
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
	if ((*env)->mlx->img)
		mlx_destroy_image((*env)->mlx->mlx, (*env)->mlx->img);
	if ((*env)->mlx->win)
		mlx_destroy_window((*env)->mlx->mlx, (*env)->mlx->win);
	if ((*env)->map)
		wolf_free_matrix(&((*env)->map), (*env)->map_sizes.y);
	if ((*env)->raw != NULL)
		wolf_free_map(&((*env)->raw));
	_FREE((*env)->mlx, free);
	_FREE((*env)->isr, free);
	_FREE(*env, free);
}
