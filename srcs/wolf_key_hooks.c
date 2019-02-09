/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:44:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/09 12:55:11 by tmaluh           ###   ########.fr       */
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
	return (0);
}
