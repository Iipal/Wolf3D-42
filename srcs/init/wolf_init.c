/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:38:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/05 11:07:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		wolf_setup_rc(t_env *env)
{
	*(env->rc) = (t_rc){{0, 0}, {0, -1}, {0.65, 0}, 0,
		{0, 0}, {0, 0}, {0, 0}, {0, 0}, 0, {0, 0},
		false, false, 0, 0, 0};
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
	env->torch->time = (t_time){0, 0, 0};
	env->mouse->is_pressed_mouse = false;
}

static bool	add_init_menu_and_text(t_env *env)
{
	_ISZ(t_menu, env->menu, 1);
	_ISZ(t_tex, env->menu->bg, 1);
	_ISZ(t_tex, env->menu->selector, 1);
	_NOTIS_F(env->menu->bg->surf =
		wolf_optimize_surf_load(MENU_BG, env->sdl->win_surface->format));
	_NOTIS_F(env->menu->selector->surf =
		SDL_CreateRGBSurface(0, SELECTOR_X, SELECTOR_Y, 32, 0, 0, 0, 0));
	SDL_FillRect(env->menu->selector->surf, NULL, IRGB_WHITE);
	_NOTIS_F(env->menu->selector->pixels = env->menu->selector->surf->pixels);
	_NOTIS_F(env->menu->bg->pixels = env->menu->bg->surf->pixels);
	_NOTIS(TTF_GetError(),
		env->sdl->font = TTF_OpenFont(FPS_FONT, 20), exit(EXIT_FAILURE), false);
	return (true);
}

static bool	add_init_audio(t_env *env)
{
	_ISM(Mix_GetError(),
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0, exit(1), false);
	_ISZ(t_sfx, env->sfx, 1);
	*(env->sfx) = (t_sfx){NULL, NULL, NULL, NULL, NULL, NULL,
		{0, 0, 0}, BG_VOL_DEF};
	_NOTIS(Mix_GetError(),
		env->sfx->ambient_bg = Mix_LoadMUS(AMBIENT_BG), exit(1), false);
	_NOTIS(Mix_GetError(),
		env->sfx->start = Mix_LoadWAV(MSTART), exit(1), false);
	_NOTIS(Mix_GetError(),
		env->sfx->selector = Mix_LoadWAV(MSELECTOR), exit(1), false);
	_NOTIS(Mix_GetError(),
		env->sfx->selector_err = Mix_LoadWAV(MSERROR), exit(1), false);
	_NOTIS(Mix_GetError(),
		env->sfx->lstep = Mix_LoadWAV(GAME_LSTEP), exit(1), false);
	_NOTIS(Mix_GetError(),
		env->sfx->rstep = Mix_LoadWAV(GAME_RSTEP), exit(1), false);
	Mix_VolumeChunk(env->sfx->lstep, 35);
	Mix_VolumeChunk(env->sfx->rstep, 35);
	Mix_PlayMusic(env->sfx->ambient_bg, -1);
	Mix_VolumeMusic(env->sfx->bg_volume / BG_VOL_MUTE);
	Mix_PlayChannel(-1, env->sfx->start, 0);
	return (true);
}

bool		wolf_init(t_env *env)
{
	env->fog = (t_fog){dark, IRGB_BLACK, 4.2, 0};
	env->bsize = BLUR_DEF;
	_ISM(SDL_GetError(), SDL_Init(SDL_INIT_EVERYTHING) < 0, exit(1), false);
	_ISM(TTF_GetError(), TTF_Init() < 0, exit(1), false);
	_ISZ(t_sdl, env->sdl, 1);
	_NOTIS(SDL_GetError(),
		env->sdl->win = SDL_CreateWindow(WOLF_TITTLE, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y, 4), exit(1), false);
	_NOTIS(SDL_GetError(),
		env->sdl->win_surface = SDL_GetWindowSurface(SWIN), exit(1), false);
	_NOTIS_F(env->sdl->win_pixels = env->sdl->win_surface->pixels);
	_ISZ(t_isr, env->isr, 1);
	*(env->isr) = (t_isr){1, 1, false, true, true, true, 0, 0, 0, 0, 0, 0};
	_ISZ(t_map, env->map, 1);
	_ISZ(t_rc, env->rc, 1);
	_ISZ(t_mouse, env->mouse, 1);
	_NOTIS_F(wolf_init_textures(env));
	_NOTIS_F(add_init_menu_and_text(env));
	_NOTIS_F(add_init_audio(env));
	return (true);
}
