/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:38:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/27 14:32:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		wolf_setup_rc(t_env *env)
{
	*(RC) = (t_rc){{0, 0}, {0, -1}, {0.65, 0}, 0,
		{0, 0}, {0, 0}, {0, 0}, {0, 0}, 0, {0, 0},
		false, false, 0, 0, 0};
	while (1)
	{
		RC->pos = (fpoint){ft_rand(MAPY - 1), ft_rand(MAPX - 1)};
		if (!MAP[(int)RC->pos.y][(int)RC->pos.x])
			break ;
	}
	if (!MAP[(int)RC->pos.y][(int)(RC->pos.x + 0.05f)])
		RC->pos.x += 0.05f;
	if (!MAP[(int)(RC->pos.y + 0.05f)][(int)RC->pos.x])
		RC->pos.y += 0.05f;
	env->torch->time = (t_time){0, 0, 0};
}

static bool	add_init_textures(t_env *env)
{
	const string	textures[] = {TEXWALL1, TEXWALL2, TEXWALL3, TEXWALL4,
		TEXWALL5, TEXWALL6, TEXWALL7, TEXWALL8, TEXFLOOR, TEXSKY};
	const string	torch[] = {TORCH1, TORCH2, TORCH3, TORCH4, TORCH5, TORCH6};
	int				i;

	i = -1;
	while (++i < (MAX_TEXTURES + 2))
	{
		_NOTIS_F(TEX[i].surf =
			wolf_optimize_surf_load(textures[i], SWINS->format));
		_NOTIS_F(TEX[i].pixels = TEX[i].surf->pixels);
		if (i < MAX_TORCH)
		{
			_NOTIS_F(TORCH->tex[i].surf =
				wolf_optimize_surf_load(torch[i], SWINS->format));
			_NOTIS_F(TORCH->tex[i].pixels = TORCH->tex[i].surf->pixels);
		}
	}
	return (true);
}

static bool	add_init_menu(t_env *env)
{
	_NOTIS_F(MENU = (t_menu*)malloc(sizeof(t_menu)));
	*(MENU) = (t_menu){NULL, NULL};
	_NOTIS_F(MENU->bg = (t_tex*)malloc(sizeof(t_tex)));
	_NOTIS_F(MENU->text = (t_tex*)malloc(sizeof(t_tex)));
	_NOTIS_F(MENU->bg->surf = wolf_optimize_surf_load(MENU_BG, SWINS->format));
	_NOTIS_F(MENU->text->surf = wolf_optimize_surf_load(MTEXT, SWINS->format));
	_NOTIS_F(MENUP = MENU->bg->surf->pixels);
	_NOTIS_F(MTEXTP = MENU->text->surf->pixels);
	return (true);
}

bool		wolf_init(t_env *env)
{
	*env = (t_env){NULL, NULL, NULL, NULL, NULL, NULL, {{0, 0, 0}, 0, 0},
		{8, IRGB_BLACK, 4.2, 0}, NULL, NULL};
	_ISM(SDL_GetError(), SDL_Init(SDL_INIT_EVERYTHING) < 0, exit(1), false);
	_NOTIS_F(env->sdl = (t_sdl*)malloc(sizeof(t_sdl)));
	_NOTIS(SDL_GetError(),
		SWIN = SDL_CreateWindow(WOLF_TITTLE, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y,
			SDL_WINDOW_SHOWN), exit(EXIT_FAILURE), false);
	_NOTIS(SDL_GetError(),
		SWINS = SDL_GetWindowSurface(SWIN), exit(EXIT_FAILURE), false);
	_NOTIS_F(SWINP = SWINS->pixels);
	_NOTIS_F(ISR = (t_isr*)malloc(sizeof(t_isr)));
	*(ISR) = (t_isr){false, true, true, true, false, false, false, false};
	_NOTIS_F(env->map = (t_map*)malloc(sizeof(t_map)));
	_NOTIS_F(RC = (t_rc*)malloc(sizeof(t_rc)));
	_NOTIS_F(MOUSE = (t_mouse*)malloc(sizeof(t_mouse)));
	_NOTIS_F(TEX = (t_tex*)malloc(sizeof(t_tex) * (MAX_TEXTURES + 2)));
	_NOTIS_F(TORCH = (t_torch*)malloc(sizeof(t_torch)));
	_NOTIS_F(TORCH->tex = (t_tex*)malloc(sizeof(t_tex) * MAX_TORCH));
	_NOTIS_F(add_init_textures(env));
	_NOTIS_F(add_init_menu(env));
	return (true);
}
