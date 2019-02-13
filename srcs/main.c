/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:19:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/13 16:58:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	wolf_usage(void)
{
	_MSGN("Usage:");
	_MSGN("  [W | S] - Moving forward | backward(or Arrows [UP | DOWN])");
	_MSGN("  [A | D] - Rotate left | right(or Arrows [LEFT | RIGHT]");
	_MSGN("  [T] - Switch Textured\\Flat rendering method.");
	_MSGN("  [ESC] - exit.");
}

static void	add_init_rc_n_randomize_pos(t_env *env)
{
	*(RC) = (t_rc){{0, 0}, {0, -1}, {0.66, 0}, 0,
		{0, 0}, {0, 0}, {0, 0}, {0, 0}, 0, {0, 0},
		false, false, 0, 0, 0};
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
	wolf_usage();
}

static void	add_mlx_hooks(t_env *env)
{
	mlx_hook(WPTR, MOUSE_DOWN, MOUSE_MASK, wolf_mouse_press, env);
	mlx_hook(WPTR, MOUSE_UP, MOUSE_MASK, wolf_mouse_release, env);
	mlx_hook(WPTR, MOUSE_MOVE, MOUSE_MASK, wolf_mouse_moves, env);
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
