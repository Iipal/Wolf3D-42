/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_fhelp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:27:02 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 11:33:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_fhelp(t_env *env, strtab av, int32_t ac)
{
	(void)ac;
	(void)av;
	(void)env;
	MSGN("All command line options for wolf3d:");
	MSGN("	-h:          print help.");
	MSGN("	-no-border:  create window without borders.");
	exit(EXIT_SUCCESS);
}
