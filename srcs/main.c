/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:19:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/22 09:47:06 by tmaluh           ###   ########.fr       */
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
	_MSGN("  [M] - Toggle mini-map drawing.");
	_MSGN("  [F] - Toggle Fog drawing.");
	_MSGN("  [C] - Switch Fog colors.");
	_MSGN("  [LShift] - Step & rotate boost.");
	_MSGN("  [ESC] - exit.");
}

int			main(int argc, string argv[])
{
	t_env	*env;

	_NOTIS(E_DIR, ft_strlen(*argv) == 8
		&& !ft_strncmp(*argv, "./wolf3d", 8), exit(EXIT_FAILURE), 0);
	_ISARGS(argc, argv);
	_NOTIS(E_ALLOC, env = (t_env*)malloc(sizeof(t_env)), exit(EXIT_FAILURE), 0);
	_NOTIS(E_ALLOC, wolf_init(env), wolf_free(&env), EXIT_FAILURE);
	_NOTIS(E_FILER, wolf_readnsave(*argv, env), exit(EXIT_FAILURE), 0);
	wolf_setup_rc(env);
	wolf_usage();
	wolf_rendering_rc(env);
	wolf_sdl_events_loop(env);
	SDL_Quit();
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
**	If all was great we can print usage & start RC rendering proccess.
**	And start main 'endless' loop where we will hook events & re-drawing all.
*/
