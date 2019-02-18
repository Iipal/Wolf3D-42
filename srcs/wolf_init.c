/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:38:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/18 17:29:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	wolf_usage(void)
{
	_MSGN("Usage:");
	_MSGN("  [W | S] - Moving forward | backward(or Arrows [UP | DOWN])");
	_MSGN("  [A | D] - Rotate left | right(or Arrows [LEFT | RIGHT]");
	_MSGN("  [T] - Toggle Textured\\Flat rendering method.");
	_MSGN("  [M] - Toggle mini-map drawing.");
	_MSGN("  [F] - Toggle Fog drawing.");
	_MSGN("  [C] - Switch Fog colors");
	_MSGN("  [LShift] - BOOST");
	_MSGN("  [ESC] - exit.");
}

void		wolf_init_rc_n_randomize_pos(t_env *env)
{
	*(RC) = (t_rc){{0, 0}, {0, -1}, {0.9, 0}, 0,
		{0, 0}, {0, 0}, {0, 0}, {0, 0}, 0, {0, 0},
		false, false, 0, 0, 0, 8, IRGB_BLACK, 4.2};
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

static bool	add_init_textures(t_env *env)
{
	const string	textures[] = {TEXWALL1, TEXWALL2, TEXWALL3, TEXWALL4,
		TEXWALL5, TEXWALL6, TEXWALL7, TEXWALL8, TEXFLOOR, TEXSKY};
	int				i;

	i = -1;
	while (++i < (MAX_TEXTURES + 2))
	{
		_NOTIS_F(TEX[i].surf =
			wolf_optimize_surf_load(textures[i], SWINS->format));
		_NOTIS_F(TEX[i].pixels = TEX[i].surf->pixels);
	}
	return (true);
}

bool		wolf_init(t_env *env)
{
	*env = (t_env){NULL, NULL, NULL, NULL, NULL, NULL};
	_NOTIS_F(env->sdl = (t_sdl*)malloc(sizeof(t_sdl)));
	_NOTIS(SDL_GetError(),
		SDL_Init(SDL_INIT_EVERYTHING) >= 0, exit(EXIT_FAILURE), false);
	_NOTIS(SDL_GetError(),
		SWIN = SDL_CreateWindow(WIN_TITTLE, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y,
			SDL_WINDOW_SHOWN), exit(EXIT_FAILURE), false);
	_NOTIS(SDL_GetError(),
		SWINS = SDL_GetWindowSurface(SWIN), exit(EXIT_FAILURE), false);
	_NOTIS_F(SWINP = SWINS->pixels);
	_NOTIS_F(env->isr = (t_isr*)malloc(sizeof(t_isr)));
	*(env->isr) = (t_isr){false, true, true, true, false, false, false, false,
		false};
	_NOTIS_F(env->map = (t_map*)malloc(sizeof(t_map)));
	_NOTIS_F(env->rc = (t_rc*)malloc(sizeof(t_rc)));
	_NOTIS_F(MOUSE = (t_mouse*)malloc(sizeof(t_mouse)));
	_NOTIS_F(TEX = (t_tex*)malloc(sizeof(t_tex) * (MAX_TEXTURES + 2)));
	_NOTIS_F(add_init_textures(env));
	return (true);
}
