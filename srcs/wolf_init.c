/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:38:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/13 17:52:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static bool	add_init_textures(t_env *env)
{
	const string	textures[] = {TEXWALL1, TEXWALL2, TEXWALL3, TEXWALL4,
		TEXWALL5, TEXWALL6, TEXWALL7, TEXWALL8, TEXFLOOR, TEXSKY};
	int				i;
	t_tim			t;

	i = -1;
	while (++i < MAX_TEXTURES + 2)
	{
		_NOTIS_F(TEX[i].xpm =
			mlx_xpm_file_to_image(MPTR, textures[i], &t.w, &t.h));
		_NOTIS_F(TEX[i].img =
			(iarr)mlx_get_data_addr(TEX[i].xpm, &t.bps, &t.sl, &t.end));
	}
	return (true);
}

bool		wolf_init(t_env *env)
{
	t_tim	t;

	*env = (t_env){NULL, NULL, NULL, NULL, NULL, NULL};
	_NOTIS_F(env->mlx = (t_mlx*)malloc(sizeof(t_mlx)));
	_NOTIS_F(MPTR = mlx_init());
	_NOTIS_F(WPTR = mlx_new_window(MPTR, WIN_X, WIN_Y, WIN_TITTLE));
	_NOTIS_F(IPTR = mlx_new_image(MPTR, WIN_X, WIN_Y));
	_NOTIS_F(SPTR = (iarr)mlx_get_data_addr(IPTR, &t.bps, &t.sl, &t.end));
	_NOTIS_F(env->isr = (t_isr*)malloc(sizeof(t_isr)));
	_NOTIS_F(env->map = (t_map*)malloc(sizeof(t_map)));
	_NOTIS_F(env->rc = (t_rc*)malloc(sizeof(t_rc)));
	_NOTIS_F(MOUSE = (t_mouse*)malloc(sizeof(t_mouse)));
	_NOTIS_F(TEX = (t_xpm*)(malloc(sizeof(t_xpm) * (MAX_TEXTURES + 2))));
	*(env->isr) = (t_isr){false, false, false};
	_NOTIS_F(add_init_textures(env));
	return (true);
}
