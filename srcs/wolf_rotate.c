/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 01:03:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/11 01:17:33 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_rotate(fpoint *fp, float angle)
{
	float	xtemp;
	float	xcos;
	float	xsin;

	xtemp = fp->x;
	xcos = cos(angle);
	xsin = sin(angle);
	fp->x = fp->x * xcos - fp->y * xsin;
	fp->y = xtemp * xsin + fp->y * xcos;
}

void		wolf_rotate(t_rc *rc, float angle)
{
	add_rotate(&(rc->plane), angle);
	add_rotate(&(rc->dir), angle);
}
