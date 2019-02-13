/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:38:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/13 10:56:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static bool	add_init_textures(t_env *env)
{
	const string	textures[] = {TEXWALL1, TEXWALL2, TEXWALL3, TEXWALL4,
		TEXWALL5, TEXWALL6, TEXWALL7, TEXWALL8, TEXFLOOR};
	int				i;
	int				w;
	int				h;

	i = -1;
	while (++i < MAX_TEXTURES + 1)
		TEX[i] = mlx_xpm_file_to_image(MPTR, textures[i], &w, &h);
	return (true);
}

bool		wolf_init(t_env *env)
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
	_NOTIS_F(TEX = (pvoid*)(malloc(sizeof(pvoid) * (MAX_TEXTURES + 1))));
	_NOTIS_F(add_init_textures(env));
	return (true);
}
