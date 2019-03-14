/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:19:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/14 16:45:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	wolf_usage(void)
{
	_MSGN("Usage:");
	_MSGN("  [W | S] - Moving forward | backward(or Arrows [UP | DOWN])");
	_MSGN("  [A | D] - Rotate left | right"
		"(also Arrows [LEFT | RIGHT] or mouse)");
	_MSGN("  [T] - Toggle Textured\\Flat rendering method.");
	_MSGN("  [M] - Toggle mini-map rendering.");
	_MSGN("  [F] - Toggle Fog rendering.");
	_MSGN("  [C] - Switch Fog colors.");
	_MSGN("  [LShift] - Step & rotate boost.");
	_MSGN("  [Z] - Stop\\Play steps sounds.");
	_MSGN("  [Q] - Stop\\Play background in-game music.");
	_MSGN("  [+ | -] - Inc\\Decrease background volume.");
	_MSGN("  [R] - Toggle FPS\\ms rendering info");
	_MSGN("  [ESC] - exit.");
}

int			main(int argc, string argv[])
{
	t_env	*env;

	// _ISM(E_DIR, ft_strcmp(*argv, WOLF_EXE_PATH), exit(EXIT_FAILURE), 0);
	_ISARGS(argc, argv);
	_ISZ(t_env, env, 1);
	_NOTIS(E_ALLOC, wolf_init(env), wolf_free(&env), EXIT_FAILURE);
	_NOTIS(E_FILER, wolf_readnsave(*argv, env), exit(EXIT_FAILURE), 0);
	wolf_setup_rc(env);
	wolf_usage();
	wolf_rendering_mainmenu(env);
	wolf_sdl_mainmenu_loop(env);
}

/*
**	Fast, short description:
**
**	For beginning need to validate executable path for correct textures loading
**		(macro on line 33).
**	Next step is validate arguments for program (only 1 must to be).
**	Allocating memory for 'main' structure & initialize SDL2/Loading textures.
**	After that we can save our map from file to `env->map`.
**	Then we can set-up default settings for RayCastring structure
**		& randomize position for bonus.
**	If all was great we can print usage & show main menu on window to start.
*/
