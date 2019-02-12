/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:38:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/12 18:38:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static bool	add_init_textures(t_env *env)
{
	if (env)
	{
	}
	return (true);
}

bool	wolf_init(t_env *env)
{
	int	bps;
	int	sz;
	int	end;

	*env = (t_env){NULL, NULL, NULL, NULL, NULL, NULL};
	_NOTIS_F(env->mlx = (t_mlx*)malloc(sizeof(t_mlx)));
	_NOTIS_F(MPTR = mlx_init());
	_NOTIS_F(WPTR = mlx_new_window(MPTR, WIN_X, WIN_Y, WIN_TITTLE));
	_NOTIS_F(IPTR = mlx_new_image(MPTR, WIN_X, WIN_Y));
	_NOTIS_F(SPTR = (iarr)mlx_get_data_addr(IPTR, &bps, &sz, &end));
	_NOTIS_F(env->isr = (t_isr*)malloc(sizeof(t_isr)));
	*(env->isr) = (t_isr){false};
	_NOTIS_F(env->map = (t_map*)malloc(sizeof(t_map)));
	_NOTIS_F(env->rc = (t_rc*)malloc(sizeof(t_rc)));
	_NOTIS_F(MOUSE = (t_mouse*)malloc(sizeof(t_mouse)));
	_NOTIS_F(TEX = (t_xpm_image*)(malloc(sizeof(t_xpm_image) * MAX_TEXTURES)));
	_NOTIS_F(add_init_textures(env));
	return (true);
}
