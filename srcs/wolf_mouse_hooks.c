/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_mouse_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:33:42 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/12 18:45:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		wolf_mouse_press(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	(void)button;
	MOUSE->is_pres = true;
	return (0);
}

int		wolf_mouse_release(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	(void)button;
	MOUSE->is_pres = false;
	return (0);
}

int		wolf_mouse_moves(int x, int y, t_env *env)
{
	MOUSE->last = MOUSE->curr;
	MOUSE->curr = (fpoint){y, x};
	if (MOUSE->is_pres)
	{
		wolf_rotate(RC, -(x - MOUSE->last.x) * 0.002);
		wolf_rendering_rc(env);
	}
	return (0);
}
