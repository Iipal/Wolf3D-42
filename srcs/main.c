/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:19:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/09 12:53:29 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_mlx_hooks(t_env *env)
{
	mlx_hook(WPTR, KEY_PRESSED, KEY_RELEASE, wolf_key_hooks, env);
	mlx_hook(WPTR, WIN_EXT, WIN_EXTM, wolf_killwindow, env);
	wolf_rendering(env);
	MPTR ? mlx_loop(MPTR) : 0;
}

int			main(int argc, string argv[])
{
	t_env	*env;

	_ISARGS(argc, argv);
	_NOTIS(E_ALLOC, env = malloc(sizeof(t_env)), exit(EXIT_FAILURE), 0);
	_NOTIS(E_ALLOC, wolf_init(env), wolf_free(&env), 0);
	_NOTIS(E_FILER, wolf_readnsave(*argv, env), exit(EXIT_FAILURE), 0);
	_NOTIS(E_ALLOC, wolf_convert_map_to_matrix(env), exit(EXIT_FAILURE), 0);
	add_mlx_hooks(env);
}
