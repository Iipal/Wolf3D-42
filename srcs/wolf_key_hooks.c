/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:44:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/15 17:03:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			wolf_killwindow(t_env *env)
{
	wolf_free(&env);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	add_actions(int key, t_env *env)
{
	if ((key == KEY_W || key == ARROW_UP) && (ISRR = true))
		wolf_move(env, ISRB ? (MOVE_BOOST * MOVE_INC) : MOVE_INC);
	if ((key == KEY_A || key == ARROW_LEFT) && (ISRR = true))
		wolf_rotate(RC, _RAD(ISRB ? (ROT_BOOST * ROT_INC) : ROT_INC));
	if ((key == KEY_S || key == ARROW_DOWN) && (ISRR = true))
		wolf_move(env, ISRB ? (MOVE_BOOST * -MOVE_INC) : -MOVE_INC);
	if ((key == KEY_D || key == ARROW_RIGHT) && (ISRR = true))
		wolf_rotate(RC, _RAD(ISRB ? (ROT_BOOST * -ROT_INC) : -ROT_INC));
}

int			wolf_key_hooks(int key, t_env *env)
{
	ISRR = false;
	if (key == ESC)
		wolf_killwindow(env);
	if (key == KEY_M && (ISRR = true))
		ISRMM = !ISRMM;
	if (key == LSHIFT && (ISRR = true))
		ISRB = !ISRB;
	if (key == KEY_T && (ISRR = true))
		ISRT = !ISRT;
	add_actions(key, env);
	if (ISRR)
		wolf_rendering_rc(env);
	return (0);
}
