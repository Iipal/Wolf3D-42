/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/06 15:05:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wolf_free(t_env *env)
{
	IPTR ? mlx_destroy_image(MPTR, IPTR) : 0;
	WPTR ? mlx_destroy_window(MPTR, WPTR) : 0;
	env->mlx ? free(env->mlx) : NULL;
	env->isr ? free(env->isr) : NULL;
	env ? free(env) : NULL;
}
