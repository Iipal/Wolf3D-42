/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:44:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/06 15:07:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		wolf_killwindow_hook(t_env *env)
{
	wolf_free(env);
	system("leaks wolf3d");
	exit(EXIT_SUCCESS);
	return (0);
}

int		wolf_key_hooks(int key, t_env *env)
{
	if (key == ESC)
		wolf_killwindow_hook(env);
	return (0);
}
