/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/09 12:58:24 by tmaluh           ###   ########.fr       */
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
			*m[i] ? free(*m[i]) : 0;
		free(*m);
		*m = NULL;
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
					free((*map)->tab[i]);
			free((*map)->tab);
		}
		if ((*map)->colors)
		{
			i = -1;
			while (++i < (*map)->ysize)
				if ((*map)->colors[i] != NULL)
					free((*map)->colors[i]);
			free((*map)->colors);
		}
		free(*map);
		*map = NULL;
	}
}

void	wolf_free(t_env **env)
{
	if ((*env)->mlx->img)
		mlx_destroy_image((*env)->mlx->mlx, (*env)->mlx->img);
	if ((*env)->mlx->win)
		mlx_destroy_window((*env)->mlx->mlx, (*env)->mlx->win);
	_FREE((*env)->mlx, free);
	_FREE((*env)->map, free);
	_FREE((*env)->isr, free);
	_FREE(*env, free);
}
