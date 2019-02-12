/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:44:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/12 13:44:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			wolf_killwindow(t_env *env)
{
	wolf_free(&env);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	add_action_wasd(int key, t_env *env)
{
	if (key == KEY_W)
		wolf_move(env, MOVE_INC);
	if (key == KEY_A)
		wolf_rotate(RC, _RAD(ROT_INC));
	if (key == KEY_S)
		wolf_move(env, -MOVE_INC);
	if (key == KEY_D)
		wolf_rotate(RC, _RAD(-ROT_INC));
}

static void	add_action_arrows(int key, t_env *env)
{
	if (key == ARROW_UP)
		wolf_move(env, MOVE_INC);
	if (key == ARROW_DOWN)
		wolf_move(env, -MOVE_INC);
	if (key == ARROW_LEFT)
		wolf_rotate(RC, _RAD(ROT_INC));
	if (key == ARROW_RIGHT)
		wolf_rotate(RC, _RAD(-ROT_INC));
}

int			wolf_key_hooks(int key, t_env *env)
{
	if (key == ESC)
		wolf_killwindow(env);
	if (key == PLUS_NUMPAD || key == PLUS_KEYBOARD)
		RC->plane = (fpoint) {RC->plane.y + FOV_INC, RC->plane.x + FOV_INC};
	if (key == MINUS_NUMPAD || key == MINUS_KEYBOARD)
		if (RC->plane.y - FOV_INC >= FOV_MIN
		&& RC->plane.x - FOV_INC >= FOV_MIN)
			RC->plane = (fpoint) {RC->plane.y - FOV_INC, RC->plane.x - FOV_INC};
	add_action_wasd(key, env);
	add_action_arrows(key, env);
	wolf_rendering_rc(env);
	return (0);
}
