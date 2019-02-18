/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_sdl_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 22:59:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/18 20:33:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_keys_press(t_env *env, bool *exit)
{
	if (SETYPE == SDL_KEYDOWN)
	{
		(SEKEY == SDLK_ESCAPE) ? (*exit = true) : 0;
		if (SEKEY == SDLK_w || SEKEY == SDLK_UP)
			ISR->is_move_forward = true;
		if (SEKEY == SDLK_a || SEKEY == SDLK_LEFT)
			ISR->is_rotate_left = true;
		if (SEKEY == SDLK_s || SEKEY == SDLK_DOWN)
			ISR->is_move_backward = true;
		if (SEKEY == SDLK_d || SEKEY == SDLK_RIGHT)
			ISR->is_rotate_right = true;
		(SEKEY == SDLK_LSHIFT) ? (ISRB = true) : 0;
		(SEKEY == SDLK_f) ? (ISRF = !ISRF) : 0;
		(SEKEY == SDLK_m) ? (ISRMM = !ISRMM) : 0;
		(SEKEY == SDLK_t) ? (ISRT = !ISRT) : 0;
		(SEKEY == SDLK_c) ? (ISR->is_change_fog_color = true) : 0;
	}
}

static void	add_keys_release(t_env *env)
{
	if (SETYPE == SDL_KEYUP)
	{
		if (SEKEY == SDLK_w || SEKEY == SDLK_UP)
			ISR->is_move_forward = false;
		if (SEKEY == SDLK_a || SEKEY == SDLK_LEFT)
			ISR->is_rotate_left = false;
		if (SEKEY == SDLK_s || SEKEY == SDLK_DOWN)
			ISR->is_move_backward = false;
		if (SEKEY == SDLK_d || SEKEY == SDLK_RIGHT)
			ISR->is_rotate_right = false;
		(SEKEY == SDLK_c) ? (ISR->is_change_fog_color = false) : 0;
		(SEKEY == SDLK_LSHIFT) ? (ISRB = false) : 0;
	}
}

static void	add_mouse_moves(t_env *env)
{
	SDL_GetMouseState(&(SEVENT.motion.x), &(SEVENT.motion.y));
	if (SEVENT.type == SDL_MOUSEBUTTONDOWN)
		MOUSE->is_pressed_mouse = true;
	if (SEVENT.type == SDL_MOUSEBUTTONUP)
		MOUSE->is_pressed_mouse = false;
	MOUSE->last = MOUSE->curr;
	MOUSE->curr = SEVENT.motion.x;
	if (MOUSE->is_pressed_mouse)
	{
		wolf_rotate(RC, -(SEVENT.motion.x - MOUSE->last) * ROT_MOUSE_INC);
	}
}

static void	add_loop_isr(t_env *env)
{
	if (ISR->is_move_forward)
		wolf_move(env, ISRB ? (MOVE_BOOST * FPS.move) : FPS.move);
	if (ISR->is_rotate_left)
		wolf_rotate(RC, _RAD(ISRB ? (ROT_BOOST * FPS.rot) : FPS.rot));
	if (ISR->is_move_backward)
		wolf_move(env, ISRB ? (MOVE_BOOST * -FPS.move) : -FPS.move);
	if (ISR->is_rotate_right)
		wolf_rotate(RC, _RAD(ISRB ? (ROT_BOOST * -FPS.rot) : -FPS.rot));
	if (ISR->is_change_fog_color)
		RC->fog_color = wolf_fog_change(&(RC->clr));
}

void		wolf_sdl_events_loop(t_env *env)
{
	bool	exit;

	exit = false;
	while (!exit)
	{
		while (SDL_PollEvent(&SEVENT) > 0)
		{
			(SETYPE == SDL_QUIT) ? (exit = true) : 0;
			add_keys_press(env, &exit);
			add_keys_release(env);
			add_mouse_moves(env);
		}
		add_loop_isr(env);
		wolf_rendering_rc(env);
	}
	SDL_DestroyWindow(SWIN);
	wolf_free(&env);
}
