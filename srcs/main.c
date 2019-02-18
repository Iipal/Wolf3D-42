/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:19:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/18 11:43:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			main(int argc, string argv[])
{
	t_env	*env;

	_NOTIS(E_DIR, ft_strlen(*argv) == 8
		&& !ft_strncmp(*argv, "./wolf3d", 8), exit(EXIT_FAILURE), 0);
	_ISARGS(argc, argv);
	_NOTIS(E_ALLOC, env = (t_env*)malloc(sizeof(t_env)), exit(EXIT_FAILURE), 0);
	_NOTIS(E_ALLOC, wolf_init(env), wolf_free(&env), EXIT_FAILURE);
	_NOTIS(E_FILER, wolf_readnsave(*argv, env), exit(EXIT_FAILURE), 0);
	wolf_init_rc_n_randomize_pos(env);
	wolf_rendering_rc(env);
	wolf_sdl_loop(env);
}
