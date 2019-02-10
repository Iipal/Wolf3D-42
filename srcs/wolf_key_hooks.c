/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:44:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/11 01:36:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			wolf_killwindow(t_env *env)
{
	wolf_free(&env);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	add_moving_camera_wasd(int key, t_env *env)
{
	if (key == KEY_W)
		if (!MAP[(int)RC->pos.y][(int)(RC->pos.x - MOVE_INC)])
			RC->pos.x -= MOVE_INC;
	if (key == KEY_A)
		if (!MAP[(int)(RC->pos.y - MOVE_INC)][(int)RC->pos.x])
			RC->pos.y -= MOVE_INC;
	if (key == KEY_S)
		if (!MAP[(int)RC->pos.y][(int)(RC->pos.x + MOVE_INC)])
			RC->pos.x += MOVE_INC;
	if (key == KEY_D)
		if (!MAP[(int)(RC->pos.y + MOVE_INC)][(int)RC->pos.x])
			RC->pos.y += MOVE_INC;
}

static void	add_rotate_camera_arrows(int key, t_env *env)
{
	if (key == ARROW_LEFT)
		wolf_rotate(RC, _RAD(ROT_INC));
	if (key == ARROW_RIGHT)
		wolf_rotate(RC, _RAD(-ROT_INC));
}

int			wolf_key_hooks(int key, t_env *env)
{
	if (key == ESC)
		wolf_killwindow(env);
	if (key == PLUS_NUMPAD)
		RC->plane = (fpoint) {RC->plane.y + FOV_INC, RC->plane.x + FOV_INC};
	if (key == MINUS_NUMPAD)
		if (RC->plane.y - FOV_INC >= FOV_MIN
		&& RC->plane.x - FOV_INC >= FOV_MIN)
			RC->plane = (fpoint) {RC->plane.y - FOV_INC, RC->plane.x - FOV_INC};
	add_moving_camera_wasd(key, env);
	add_rotate_camera_arrows(key, env);
	wolf_rendering_rc(env);
	return (0);
}
