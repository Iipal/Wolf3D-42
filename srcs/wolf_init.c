/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:38:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/09 12:30:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

bool	wolf_convert_map_to_matrix(t_env *env)
{
	point	p;
	point	r;
	point	b;
	int		iwall;

	env->map_sizes = (point){RAWY * 10, RAWX * 10};
	_NOTIS_F(env->map = (t_matrix**)malloc(sizeof(t_matrix*) * MAPY));
	b = (point){1, 1};
	r.y = 0;
	p.y = -1;
	while (++(p.y) < MAPY && !(p.x = 0))
	{
		_NOTIS_F(env->map[p.y] = (t_matrix*)malloc(sizeof(t_matrix) * MAPX));
		iwall = 0;
		r.x = 0;
		while (p.x < MAPX && (iwall += 10))
		{
			while (p.x < iwall)
			{
				MAP[p.y][p.x].pos = (fpoint){p.y, p.x};
				MAP[p.y][(p.x)++].rgb = RAWC[r.y][r.x];
			}
			++r.x;
		}
		if (!((p.y + 1) % 10))
			++r.y;
	}
	wolf_free_map(env->raw);
	env->raw = NULL;
	return (true);
}

bool	wolf_init(t_env *env)
{
	int	bps;
	int	sz;
	int	end;

	*env = (t_env){NULL, NULL, NULL, NULL, {0, 0}};
	_NOTIS_F(env->mlx = malloc(sizeof(t_mlx)));
	_NOTIS_F(MPTR = mlx_init());
	_NOTIS_F(WPTR = mlx_new_window(MPTR, WIN_X, WIN_Y, WIN_TITTLE));
	_NOTIS_F(IPTR = mlx_new_image(MPTR, WIN_X, WIN_Y));
	_NOTIS_F(SPTR = (iarr)mlx_get_data_addr(IPTR, &bps, &sz, &end));
	_NOTIS_F(env->isr = malloc(sizeof(t_isr)));
	_NOTIS_F(env->raw = malloc(sizeof(t_map)));
	return (true);
}
