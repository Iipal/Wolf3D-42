/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_fparser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:16:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/11 22:45:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

bool		add_fparse_current(t_env *env, string flag, strtab av, int32_t ac)
{
	const string	flags[] = {F_HELP, F_WIN_NO_BORDER, F_DEBUG_INFO,
		F_NO_SOUND, F_ALWAYS_MOUSE, F_NO_MENU, F_NO_FOG, F_DIFF_SIDE};
	const string	short_flags[] = {FS_HELP, FS_WIN_NO_BORDER, FS_DEBUG_INFO,
		FS_NO_SOUND, FS_ALWAYS_MOUSE, FS_NO_MENU, FS_NO_FOG, FS_DIFF_SIDE};
	const f_fnptr	f_fns[] = {wolf_fhelp, wolf_fnoborder, wolf_fdebug_info,
		wolf_fno_sound, wolf_fmouse, wolf_fno_menu, wolf_no_fog,
		wolf_ftex_sides_of_world};
	bool			is_valid_flag;
	size_t			i;

	i = ~0UL;
	is_valid_flag = false;
	while (F_MAX > ++i)
		if (ft_is_one_of_str(flag, false, 2, flags[i], short_flags[i]))
		{
			is_valid_flag = true;
			f_fns[i](env, av, ac);
			break ;
		}
	return (is_valid_flag);
}

bool		wolf_fparser(t_env *env, strtab av, int32_t ac)
{
	size_t	i;

	i = ~0UL;
	while ((size_t)ac > ++i)
		if (av[i][0] == '-' && ft_isalpha(av[i][1]))
		{
			NODOM_F(E_IFLAG, add_fparse_current(env, av[i], av, ac),
				wolf_free(&env));
		}
		else
		{
			MSGN(E_IFLAG);
			wolf_free(&env);
		}
	return (true);
}
