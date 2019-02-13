/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:44:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/13 22:00:02 by tmaluh           ###   ########.fr       */
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
	if (key == KEY_W && (ISRR = true))
		wolf_move(env, ISRB ? (MOVE_BOOST * MOVE_INC) : MOVE_INC);
	if (key == KEY_A && (ISRR = true))
		wolf_rotate(RC, _RAD(ISRB ? (ROT_BOOST * ROT_INC) : ROT_INC));
	if (key == KEY_S && (ISRR = true))
		wolf_move(env, ISRB ? (MOVE_BOOST * -MOVE_INC) : -MOVE_INC);
	if (key == KEY_D && (ISRR = true))
		wolf_rotate(RC, _RAD(ISRB ? (ROT_BOOST * -ROT_INC) : -ROT_INC));
}

static void	add_action_arrows(int key, t_env *env)
{
	if (key == ARROW_UP && (ISRR = true))
		wolf_move(env, ISRB ? (MOVE_BOOST * MOVE_INC) : MOVE_INC);
	if (key == ARROW_DOWN && (ISRR = true))
		wolf_move(env, ISRB ? (MOVE_BOOST * -MOVE_INC) : -MOVE_INC);
	if (key == ARROW_LEFT && (ISRR = true))
		wolf_rotate(RC, _RAD(ISRB ? (ROT_BOOST * ROT_INC) : ROT_INC));
	if (key == ARROW_RIGHT && (ISRR = true))
		wolf_rotate(RC, _RAD(ISRB ? (ROT_BOOST * -ROT_INC) : -ROT_INC));
}

int			wolf_key_hooks(int key, t_env *env)
{
	ISRR = false;
	if (key == ESC)
		wolf_killwindow(env);
	if (key == LSHIFT && (ISRR = true))
		ISRB ? (ISRB = false)
			: (ISRB = true);
	if (key == KEY_T && (ISRR = true))
		ISRT ? (ISRT = false)
			: (ISRT = true);
	add_action_wasd(key, env);
	add_action_arrows(key, env);
	if (ISRR)
		wolf_rendering_rc(env);
	return (0);
}
