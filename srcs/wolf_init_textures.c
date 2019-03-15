/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:38:52 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/15 12:26:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static bool	add_init_textures_map(t_env *env)
{
	point	p;
	int		i;

	i = -1;
	_NOTIS_F(env->floor_and_sky->surf =
		wolf_optimize_surf_load(FLOORNSKY, env->sdl->win_surface->format));
	_NOTIS_F(env->floor_and_sky->pixels = env->floor_and_sky->surf->pixels);
	_NOTIS_F(env->walls->data->surf =
		wolf_optimize_surf_load(WALLTEXTURES, env->sdl->win_surface->format));
	_NOTIS_F(env->walls->data->pixels = env->walls->data->surf->pixels);
	env->walls->in_column = env->walls->data->surf->h / WALLS_BLOCK_SIZE;
	env->walls->in_row = env->walls->data->surf->w / WALLS_BLOCK_SIZE;
	env->walls->max_textures = env->walls->in_column * env->walls->in_row;
	_ISZ(point, env->walls->start, env->walls->max_textures);
	i = -1;
	p = (point){0, 0};
	while (++i < env->walls->max_textures)
	{
		env->walls->start[i] = (point){p.y, p.x};
		p.x += WALLS_BLOCK_SIZE;
		if (!((i + 1) % (env->walls->max_textures / env->walls->in_column)))
			p = (point){p.y + WALLS_BLOCK_SIZE, 0};
	}
	return (true);
}

bool		wolf_init_textures(t_env *env)
{
	const string	torch[] = {TORCH1, TORCH2, TORCH3, TORCH4, TORCH5, TORCH6};
	int				i;

	i = -1;
	_ISZ(t_torch, env->torch, 1);
	_ISZ(t_tex, env->torch->tex, MAX_TORCH);
	_ISZ(t_tex, env->floor_and_sky, 1);
	_ISZ(t_walls, env->walls, 1);
	_ISZ(t_tex, env->walls->data, 1);
	while (++i < MAX_TORCH)
		_NOTIS_F((env->torch->tex[i].surf =
			wolf_optimize_surf_load(torch[i], env->sdl->win_surface->format))
			&& (env->torch->tex[i].pixels = env->torch->tex[i].surf->pixels));
	add_init_textures_map(env);
	return (true);
}
