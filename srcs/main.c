/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:19:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/12 13:22:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

void	add_init_rc_n_randomize_pos(t_env *env)
{
	*(RC) = (t_rc){{0, 0}, {0, -1}, {0.66, 0}, 0,
		{0, 0}, {0, 0}, {0, 0}, {0, 0}, 0, {0, 0},
		false, false, 0, 0, 0, 0};
	while (1)
	{
		RC->pos = (fpoint){ft_rand(MAPY - 1), ft_rand(MAPX - 1)};
		if (!MAP[(int)RC->pos.y][(int)RC->pos.x])
			break ;
	}
	if (!MAP[(int)RC->pos.y][(int)(RC->pos.x + MOVE_INC)])
		RC->pos.x += MOVE_INC;
	if (!MAP[(int)(RC->pos.y + MOVE_INC)][(int)RC->pos.x])
		RC->pos.y += MOVE_INC;
}

static void	add_mlx_hooks(t_env *env)
{
	mlx_hook(WPTR, KEY_PRESSED, KEY_RELEASE, wolf_key_hooks, env);
	mlx_hook(WPTR, WIN_EXT, WIN_EXTM, wolf_killwindow, env);
	wolf_rendering_rc(env);
	MPTR ? mlx_loop(MPTR) : 0;
}

int			main(int argc, string argv[])
{
	t_env	*env;

	_ISARGS(argc, argv);
	_NOTIS(E_ALLOC, env = (t_env*)malloc(sizeof(t_env)), exit(EXIT_FAILURE), 0);
	_NOTIS(E_ALLOC, wolf_init(env), wolf_free(&env), 0);
	_NOTIS(E_FILER, wolf_readnsave(*argv, env), exit(EXIT_FAILURE), 0);
	add_init_rc_n_randomize_pos(env);
	add_mlx_hooks(env);
}
