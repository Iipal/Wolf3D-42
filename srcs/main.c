/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:19:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 20:33:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	add_start_game(t_env *env)
{
	bool	exit_;

	exit_ = false;
	while (true != exit_)
	{
		while (SDL_PollEvent(&env->sdl->event) > 0)
			wolf_sdl_mainmenu_loop(env, &exit_);
		(true == env->isr->is_play_music) ?
			Mix_ResumeMusic() : Mix_PauseMusic();
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
	NOTIS(E_FILEXT, !ft_strcmp(argv[argc - 1] +
		(ft_strlen(argv[argc - 1]) - ft_strlen(WOLF_FILE_EXT)), WOLF_FILE_EXT),
		wolf_free(&env), false);
	NOTIS_F(wolf_fparser(env, argv, argc - 1));
	NOTIS(E_FILER, wolf_readnsave(argv[argc - 1], env), exit(EXIT_FAILURE), 0);
	wolf_setup_rc(env);
	NOTIS(E_OPEN, ft_putfile(USAGE_GAME_FILE), exit(EXIT_FAILURE), -1);
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
