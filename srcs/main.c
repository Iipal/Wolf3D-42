/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:19:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/05 15:52:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	wolf_usage(void)
{
	MSGN("Usage:");
	MSGN("  [W | S] - Moving forward | backward(or Arrows [UP | DOWN])");
	MSGN("  [A | D] - Rotate left | right"
		"(also Arrows [LEFT | RIGHT] or mouse)");
	MSGN("  [T] - Toggle Textured\\Flat rendering method.");
	MSGN("  [M] - Toggle mini-map rendering.");
	MSGN("  [F] - Toggle Fog rendering.");
	MSGN("  [C] - Switch Fog colors.");
	MSGN("  [LShift] - Step & rotate boost.");
	MSGN("  [Z] - Stop\\Play steps sounds.");
	MSGN("  [Q] - Stop\\Play background in-game music.");
	MSGN("  [+ | -] - Inc\\Decrease background volume.");
	MSGN("  [R] - Toggle FPS\\ms rendering info.");
	MSGN("  [H] - Toggle blur effect rendering.");
	MSGN("  [Y | N] - Inc\\Decreaase bluring effect.");
	MSGN("  [ESC] - exit.");
}

static void	add_start_game(t_env *env)
{
	bool	exit_;

	exit_ = false;
	while (!exit_)
	{
		while (SDL_PollEvent(&env->sdl->event) > 0)
			wolf_sdl_mainmenu_loop(env, &exit_);
		(env->isr->is_play_music) ? Mix_ResumeMusic() : Mix_PauseMusic();
		wolf_rendering_mainmenu(env);
	}
}

int			main(int argc, string argv[])
{
	t_env	*env;

	ISM(E_DIR, ft_strcmp(*argv, WOLF_EXE_PATH), exit(EXIT_FAILURE), 0);
	ISARGS(argc, argv);
	ISZ(t_env, env, 1);
	NOTIS(E_ALLOC, wolf_init(env), wolf_free(&env), EXIT_FAILURE);
	NOTIS(E_FILER, wolf_readnsave(*argv, env), exit(EXIT_FAILURE), 0);
	wolf_setup_rc(env);
	wolf_usage();
	wolf_rendering_mainmenu(env);
	add_start_game(env);
	wolf_free(&env);
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
