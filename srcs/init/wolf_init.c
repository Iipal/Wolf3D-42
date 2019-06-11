/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:38:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/11 21:51:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		wolf_setup_rc(t_env *env)
{
	env->rc->dir.x = -1;
	env->rc->plane.y = .65f;
	while (1)
	{
		env->rc->pos = (fpoint){ft_rand(env->map->size.y - 1),
			ft_rand(env->map->size.x - 1)};
		if (!env->map->tab[(int32_t)env->rc->pos.y][(int32_t)env->rc->pos.x])
			break ;
	}
	if (!env->map->tab[(int32_t)env->rc->pos.y]
						[(int32_t)(env->rc->pos.x + 0.05f)])
		env->rc->pos.x += 0.05f;
	if (!env->map->tab[(int32_t)(env->rc->pos.y + 0.05f)]
						[(int32_t)env->rc->pos.x])
		env->rc->pos.y += 0.05f;
}

static bool	add_init_menu_and_text(t_env *env)
{
	MEM(t_menu, env->menu, 1, E_ALLOC);
	MEM(t_tex, env->menu->bg, 1, E_ALLOC);
	MEM(t_tex, env->menu->selector, 1, E_ALLOC);
	NO_F(env->menu->bg->surf =
		wolf_optimize_surf_load(MENU_BG, env->sdl->win_surface->format));
	NO_F(env->menu->selector->surf =
		SDL_CreateRGBSurface(0, SELECTOR_X, SELECTOR_Y, 32, 0, 0, 0, 0));
	SDL_FillRect(env->menu->selector->surf, NULL, RGB_WHITE);
	NO_F(env->menu->selector->pixels = env->menu->selector->surf->pixels);
	NO_F(env->menu->bg->pixels = env->menu->bg->surf->pixels);
	NOM_F(TTF_GetError(), env->sdl->font = TTF_OpenFont(FPS_FONT, 20));
	env->menu->is_selector_start = true;
	return (true);
}

static bool	add_init_audio(t_env *env)
{
	IFM_F(Mix_GetError(),
		0 > Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048));
	MEM(t_sfx, env->sfx, 1, E_ALLOC);
	*(env->sfx) = (t_sfx){NULL, NULL, NULL, NULL, NULL, NULL,
		{0, 0, 0}, BG_VOL_DEF};
	NOM_F(Mix_GetError(), env->sfx->ambient_bg = Mix_LoadMUS(AMBIENT_BG));
	NOM_F(Mix_GetError(), env->sfx->start = Mix_LoadWAV(MSTART));
	NOM_F(Mix_GetError(), env->sfx->selector = Mix_LoadWAV(MSELECTOR));
	NOM_F(Mix_GetError(), env->sfx->selector_err = Mix_LoadWAV(MSERROR));
	NOM_F(Mix_GetError(), env->sfx->lstep = Mix_LoadWAV(GAME_LSTEP));
	NOM_F(Mix_GetError(), env->sfx->rstep = Mix_LoadWAV(GAME_RSTEP));
	Mix_VolumeChunk(env->sfx->lstep, 35);
	Mix_VolumeChunk(env->sfx->rstep, 35);
	Mix_PlayMusic(env->sfx->ambient_bg, -1);
	Mix_VolumeMusic(env->sfx->bg_volume / BG_VOL_MUTE);
	Mix_PlayChannel(-1, env->sfx->start, 0);
	return (true);
}

bool		wolf_init(t_env *env)
{
	env->fog = (t_fog){dark, RGB_BLACK, 4.2, 0};
	env->bsize = BLUR_DEF;
	IFM_F(SDL_GetError(), SDL_Init(SDL_INIT_EVERYTHING) < 0);
	IFM_F(TTF_GetError(), TTF_Init() < 0);
	MEM(t_sdl, env->sdl, 1, E_ALLOC);
	NOM_F(SDL_GetError(),
		env->sdl->win = SDL_CreateWindow(WOLF_TITLE, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y, 4));
	NOM_F(SDL_GetError(),
		env->sdl->win_surface = SDL_GetWindowSurface(SWIN));
	NO_F(env->sdl->win_pixels = env->sdl->win_surface->pixels);
	MEM(t_isr, env->isr, 1, E_ALLOC);
	*(env->isr) = (t_isr){1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	MEM(t_map, env->map, 1, E_ALLOC);
	MEM(t_rc, env->rc, 1, E_ALLOC);
	MEM(t_mouse, env->mouse, 1, E_ALLOC);
	NO_F(wolf_init_textures(env));
	NO_F(add_init_menu_and_text(env));
	NO_F(add_init_audio(env));
	return (true);
}
