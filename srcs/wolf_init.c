/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:38:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/09 17:55:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

bool	wolf_init(t_env *env)
{
	int	bps;
	int	sz;
	int	end;

	*env = (t_env){NULL, NULL, NULL, NULL};
	_NOTIS_F(env->mlx = malloc(sizeof(t_mlx)));
	_NOTIS_F(MPTR = mlx_init());
	_NOTIS_F(WPTR = mlx_new_window(MPTR, WIN_X, WIN_Y, WIN_TITTLE));
	_NOTIS_F(IPTR = mlx_new_image(MPTR, WIN_X, WIN_Y));
	_NOTIS_F(SPTR = (iarr)mlx_get_data_addr(IPTR, &bps, &sz, &end));
	_NOTIS_F(env->isr = malloc(sizeof(t_isr)));
	_NOTIS_F(env->map = malloc(sizeof(t_map)));
	_NOTIS_F(env->rc = malloc(sizeof(t_rc)));
	return (true);
}
