/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_fparser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:16:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 19:58:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	add_fdebug_info(t_env *env, strtab av, int32_t ac)
{
	(void)av;
	(void)ac;
	*(env->isr) = (t_isr){false, false, false, true, false, false, true,
						false, false, false, false, false, false};
}

static void	add_fno_sound(t_env *env, strtab av, int32_t ac)
{
	(void)av;
	(void)ac;
	env->isr->is_play_music = false;
	env->isr->is_play_steps = false;
}

bool		add_fparse_current(t_env *env, string flag, strtab av, int32_t ac)
{
	const string	flags[] = {F_HELP, F_WIN_NO_BORDER, F_DEBUG_INFO,
					F_NO_SOUND, F_ALWAYS_MOUSE};
	const string	short_flags[] = {FS_HELP, FS_WIN_NO_BORDER, FS_DEBUG_INFO,
					FS_NO_SOUND, FS_ALWAYS_MOUSE};
	const f_fnptr	f_fns[] = {wolf_fhelp, wolf_fnoborder, add_fdebug_info,
					add_fno_sound, wolf_fmouse};
	bool			is_valid_flag;
	int8_t			i;

	i = -true;
	is_valid_flag = false;
	while (F_MAX > ++i)
		if (!ft_strcmp(flag, flags[i]) || !ft_strcmp(flag, short_flags[i]))
		{
			is_valid_flag = true;
			f_fns[i](env, av, ac);
			break ;
		}
	return (is_valid_flag);
}

bool		wolf_fparser(t_env *env, strtab av, int32_t ac)
{
	int32_t	i;

	i = -1;
	while (ac > ++i)
		if (av[i][0] == '-')
		{
			NOTIS(E_IFLAG, add_fparse_current(env, av[i], av, ac),
				wolf_free(&env), false);
		}
		else
			NOTIS2(E_IFLAG, false, wolf_free(&env), exit(EXIT_FAILURE));
	return (true);
}
