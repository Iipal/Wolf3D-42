/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:16:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/07 17:51:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	add_flag_help(t_env *env, strtab av, int32_t ac)
{
	(void)ac;
	(void)av;
	(void)env;
	MSGN("All command line options for wolf3d:");
	MSGN("	-h:          print help.");
	MSGN("	-no-border:  create window without borders.");
	exit(EXIT_SUCCESS);
}

void	add_flag_noborder(t_env *env, strtab av, int32_t ac)
{
	(void)ac;
	(void)av;
	FREE(env->sdl->win, SDL_DestroyWindow);
	env->sdl->win = SDL_CreateWindow(WOLF_TITTLE, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y, 4 | 16);
	if (NULL == env->sdl->win)
	{
		MSGN(SDL_GetError());
		wolf_free(&env);
		exit(EXIT_FAILURE);
	}
	env->sdl->win_surface = SDL_GetWindowSurface(env->sdl->win);
	env->sdl->win_pixels = env->sdl->win_surface->pixels;
}

void	add_parse_current_flag(t_env *env, string flag, strtab av, int32_t ac)
{
	const string	flags[] = {F_HELP, F_WIN_NO_BORDER};
	const f_fnptr	f_fns[] = {add_flag_help, add_flag_noborder};
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
	if (!is_valid_flag)
	{
		MSGN(E_IFLAG);
		wolf_free(&env);
		exit(EXIT_FAILURE);
	}
}

void	wolf_parser(t_env *env, strtab av, int32_t ac)
{
	int32_t	i;

	i = -1;
	while (++i < ac)
		if (av[i][0] == '-')
			add_parse_current_flag(env, av[i], av, ac);
}
