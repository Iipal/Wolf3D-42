/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:19:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/11 22:57:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

	// IFM_F(E_DIR, ft_strcmp(*argv, WOLF_EXE_PATH));
	ISARGS(argc, argv, E_USAGE);
	MEM(t_env, env, 1, E_ALLOC);
	NODOM_F(E_ALLOC, wolf_init(env), wolf_free(&env));
	NODOM_F(E_FILEXT, !ft_strcmp(argv[argc - 1] +
		(ft_strlen(argv[argc - 1]) - ft_strlen(WOLF_FILE_EXT)), WOLF_FILE_EXT),
		wolf_free(&env));
	NO_F(wolf_fparser(env, argv, argc - 1));
	NODOM_F(E_FILER, wolf_readnsave(argv[argc - 1], env), wolf_free(&env));
	wolf_setup_rc(env);
	NOM_F(E_OPEN, ft_putfile(USAGE_GAME_FILE));
	if (env->isr->is_no_main_menu)
		wolf_sdl_rendering_loop(env);
	else
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
