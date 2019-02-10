/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:44:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/11 00:36:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		wolf_killwindow(t_env *env)
{
	wolf_free(&env);
	exit(EXIT_SUCCESS);
	return (0);
}

int		wolf_key_hooks(int key, t_env *env)
{
	if (key == ESC)
		wolf_killwindow(env);
	if (key == PLUS_NUMPAD)
		RC->plane = (fpoint){RC->plane.y + 0.05, RC->plane.x + 0.05};
	if (key == MINUS_NUMPAD)
		if (RC->plane.y - 0.05 >= 0.0 &&
			RC->plane.x - 0.05 >= 0.0)
			RC->plane = (fpoint){RC->plane.y - 0.05, RC->plane.x - 0.05};
	if (key == KEY_W)
		if (MAP[(int)RC->pos.y][(int)(RC->pos.x - 0.05)] == 0)
			RC->pos.x -= 0.05;
	if (key == KEY_A)
		if (MAP[(int)(RC->pos.y - 0.05)][(int)RC->pos.x] == 0)
			RC->pos.y -= 0.05;
	if (key == KEY_S)
		if (MAP[(int)RC->pos.y][(int)(RC->pos.x + 0.05)] == 0)
			RC->pos.x += 0.05;
	if (key == KEY_D)
		if (MAP[(int)(RC->pos.y + 0.05)][(int)RC->pos.x] == 0)
			RC->pos.y += 0.05;
	wolf_rendering(env);
	return (0);
}
