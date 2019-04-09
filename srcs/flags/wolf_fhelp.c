/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_fhelp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:27:02 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 12:30:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_fhelp(t_env *env, strtab av, int32_t ac)
{
	(void)ac;
	(void)av;
	(void)env;
	IFDO(!ft_putfile(USAGE_FLAG_FILE), MSGN(E_OPEN));
	exit(EXIT_SUCCESS);
}
