/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_fparser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:16:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/07 21:55:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

bool	add_fparse_current(t_env *env, string flag, strtab av, int32_t ac)
{
	const string	flags[] = {F_HELP, F_WIN_NO_BORDER};
	const f_fnptr	f_fns[] = {wolf_fhelp, wolf_fnoborder};
	bool			is_valid_flag;
	int8_t			i;

	i = -1;
	is_valid_flag = false;
	while (++i < F_MAX)
		if (!ft_strcmp(flag, flags[i]))
		{
			is_valid_flag = true;
			f_fns[i](env, av, ac);
			break ;
		}
	return is_valid_flag;
}

bool	wolf_fparser(t_env *env, strtab av, int32_t ac)
{
	int32_t	i;

	i = -1;
	while (++i < ac)
		if (av[i][0] == '-')
			NOTIS(E_IFLAG, add_fparse_current(env, av[i], av, ac),
				wolf_free(&env), false);
	return true;
}
