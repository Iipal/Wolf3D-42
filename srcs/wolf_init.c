/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:38:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/07 16:44:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		wolf_setup_rc(t_env *env)
{
	*(env->rc) = (t_rc){{0, 0}, {0, -1}, {0.65, 0}, 0,
		{0, 0}, {0, 0}, {0, 0}, {0, 0}, 0, {0, 0},
		false, false, 0, 0, 0};
	while (1)
	{
		env->rc->pos = (fpoint){ft_rand(env->map->ysize - 1),
			ft_rand(env->map->xsize - 1)};
		if (!env->map->tab[(int)env->rc->pos.y][(int)env->rc->pos.x])
			break ;
	}
	if (!env->map->tab[(int)env->rc->pos.y][(int)(env->rc->pos.x + 0.05f)])
		env->rc->pos.x += 0.05f;
	if (!env->map->tab[(int)(env->rc->pos.y + 0.05f)][(int)env->rc->pos.x])
		env->rc->pos.y += 0.05f;
	env->torch->time = (t_time){0, 0, 0};
	env->mouse->is_pressed_mouse = false;
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
		_NOTIS_F(env->textures[i].surf = wolf_optimize_surf_load(textures[i],
			env->sdl->win_surface->format));
		_NOTIS_F(env->textures[i].pixels = env->textures[i].surf->pixels);
		if (i < MAX_TORCH)
		{
			_NOTIS_F(env->torch->tex[i].surf =
				wolf_optimize_surf_load(torch[i],
				env->sdl->win_surface->format));
			_NOTIS_F(env->torch->tex[i].pixels =
				env->torch->tex[i].surf->pixels);
		}
	}
	return (true);
}

static bool	add_init_menu_and_text(t_env *env)
{
	_NOTIS_F(env->menu = (t_menu*)malloc(sizeof(t_menu)));
	*(env->menu) = (t_menu){NULL, NULL, true};
	_NOTIS_F(env->menu->bg = (t_tex*)malloc(sizeof(t_tex)));
	_NOTIS_F(env->menu->selector = (t_tex*)malloc(sizeof(t_tex)));
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
	_NOTIS_F(env->sfx = (t_sfx*)malloc(sizeof(t_sfx)));
	*(env->sfx) = (t_sfx){NULL, NULL, NULL, NULL, NULL, NULL, {0, 0, 0}, BG_VOL_DEF};
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
	*env = (t_env){NULL, NULL, NULL, NULL, NULL, NULL, {{0, 0, 0}, 0, 0},
		{8, IRGB_BLACK, 4.2, 0}, NULL, NULL, NULL};
	_ISM(SDL_GetError(), SDL_Init(SDL_INIT_EVERYTHING) < 0, exit(1), false);
	_ISM(TTF_GetError(), TTF_Init() < 0, exit(1), false);
	_NOTIS_F(env->sdl = (t_sdl*)malloc(sizeof(t_sdl)));
	*(env->sdl) = (t_sdl){NULL, NULL, {0}, NULL, NULL, NULL};
	_NOTIS(SDL_GetError(),
		env->sdl->win = SDL_CreateWindow(WOLF_TITTLE, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y, 4), exit(1), false);
	_NOTIS(SDL_GetError(),
		env->sdl->win_surface = SDL_GetWindowSurface(SWIN), exit(1), false);
	_NOTIS_F(env->sdl->win_pixels = env->sdl->win_surface->pixels);
	_NOTIS_F(env->isr = (t_isr*)malloc(sizeof(t_isr)));
	*(env->isr) = (t_isr){1, 1, false, true, true, true, 0, false, false, 0, 0};
	_NOTIS_F(env->map = (t_map*)malloc(sizeof(t_map)));
	_NOTIS_F(env->rc = (t_rc*)malloc(sizeof(t_rc)));
	_NOTIS_F(env->mouse = (t_mouse*)malloc(sizeof(t_mouse)));
	_NOTIS_F(env->textures =
		(t_tex*)malloc(sizeof(t_tex) * (MAX_TEXTURES + 2)));
	_NOTIS_F(env->torch = (t_torch*)malloc(sizeof(t_torch)));
	_NOTIS_F(env->torch->tex = (t_tex*)malloc(sizeof(t_tex) * MAX_TORCH));
	_NOTIS_F(add_init_textures(env));
	_NOTIS_F(add_init_menu_and_text(env));
	_NOTIS_F(add_init_audio(env));
	return (true);
}
