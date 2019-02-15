/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:19:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/15 10:20:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_mlx_hooks(t_env *env)
{
	mlx_hook(WPTR, KEY_PRESSED, KEY_RELEASE, wolf_key_hooks, env);
	mlx_hook(WPTR, MOUSE_DOWN, MOUSE_MASK, wolf_mouse_press, env);
	mlx_hook(WPTR, MOUSE_UP, MOUSE_MASK, wolf_mouse_release, env);
	mlx_hook(WPTR, MOUSE_MOVE, MOUSE_MASK, wolf_mouse_moves, env);
	mlx_hook(WPTR, WIN_EXT, WIN_EXTM, wolf_killwindow, env);
	wolf_rendering_rc(env);
	MPTR ? mlx_loop(MPTR) : 0;
}

int			main(int argc, string argv[])
{
	t_env	*env;

	
	_NOTIS(E_DIR, ft_strlen(*argv) == 8 && !ft_strncmp(*argv, "./wolf3d", 8),
		exit(EXIT_FAILURE), 0);
	_ISARGS(argc, argv);
	_NOTIS(E_ALLOC, env = (t_env*)malloc(sizeof(t_env)), exit(EXIT_FAILURE), 0);
	_NOTIS(E_ALLOC, wolf_init(env), wolf_free(&env), EXIT_FAILURE);
	_NOTIS(E_FILER, wolf_readnsave(*argv, env), exit(EXIT_FAILURE), 0);
	wolf_init_rc_n_randomize_pos(env);
	add_mlx_hooks(env);
}
