/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:38:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/16 09:33:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	wolf_usage(void)
{
	_MSGN("Usage:");
	_MSGN("  [W | S] - Moving forward | backward(or Arrows [UP | DOWN])");
	_MSGN("  [A | D] - Rotate left | right(or Arrows [LEFT | RIGHT]");
	_MSGN("  [T] - Toggle Textured\\Flat rendering method.");
	_MSGN("  [M] - Toggle map drawing.")
	_MSGN("  [ESC] - exit.");
}

void		wolf_init_rc_n_randomize_pos(t_env *env)
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

bool		wolf_init(t_env *env)
{
	// t_tim	t;

	*env = (t_env){NULL, NULL, NULL, NULL, NULL, NULL};
	_NOTIS_F(env->sdl = (t_sdl*)malloc(sizeof(t_sdl)));
	_NOTIS(SDL_GetError(), SDL_Init(SDL_INIT_EVERYTHING) >= 0, exit(EXIT_FAILURE), false);
	_NOTIS(SDL_GetError(), SWIN = SDL_CreateWindow(WIN_TITTLE, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y, SDL_WINDOW_SHOWN), exit(EXIT_FAILURE), false);
	_NOTIS(SDL_GetError(), SWINS = SDL_GetWindowSurface(SWIN), exit(EXIT_FAILURE), false);
	SDL_FillRect(SWINS, NULL, SDL_MapRGB(SWINS->format, 0xff, 0xff, 0xff));
	SDL_UpdateWindowSurface(SWIN);
	_NOTIS_F(env->isr = (t_isr*)malloc(sizeof(t_isr)));
	_NOTIS_F(env->map = (t_map*)malloc(sizeof(t_map)));
	_NOTIS_F(env->rc = (t_rc*)malloc(sizeof(t_rc)));
	_NOTIS_F(MOUSE = (t_mouse*)malloc(sizeof(t_mouse)));
	SWINP = SWINS->pixels;
	*(env->isr) = (t_isr){true, false, false, false, true};
	// _NOTIS_F(add_init_textures(env));
	return (true);
}
