/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_sdl_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 22:59:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/18 15:34:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_keys_down(t_env *env)
{
	if (SEKEY == SDLK_w || SEKEY == SDLK_UP)
		ISR->is_move_forward = true;
	if (SEKEY == SDLK_a || SEKEY == SDLK_LEFT)
		ISR->is_rotate_left = true;
	if (SEKEY == SDLK_s || SEKEY == SDLK_DOWN)
		ISR->is_move_backward = true;
	if (SEKEY == SDLK_d || SEKEY == SDLK_RIGHT)
		ISR->is_rotate_right = true;
	if (SEKEY == SDLK_f)
		ISRF = !ISRF;
	if (SEKEY == SDLK_m)
		ISRMM = !ISRMM;
	if (SEKEY == SDLK_LSHIFT)
		ISRB = !ISRB;
	if (SEKEY == SDLK_t)
		ISRT = !ISRT;
	if (SEKEY == SDLK_c)
		RC->fog_color = wolf_fog_change(&(RC->clr));
}

static void	add_keys_up(t_env *env)
{
	if (SEKEY == SDLK_w || SEKEY == SDLK_UP)
		ISR->is_move_forward = false;
	if (SEKEY == SDLK_a || SEKEY == SDLK_LEFT)
		ISR->is_rotate_left = false;
	if (SEKEY == SDLK_s || SEKEY == SDLK_DOWN)
		ISR->is_move_backward = false;
	if (SEKEY == SDLK_d || SEKEY == SDLK_RIGHT)
		ISR->is_rotate_right = false;
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
		wolf_move(env, ISRB ? (MOVE_BOOST * MOVE_INC) : MOVE_INC);
	if (ISR->is_rotate_left)
		wolf_rotate(RC, _RAD(ISRB ? (ROT_BOOST * ROT_INC) : ROT_INC));
	if (ISR->is_move_backward)
		wolf_move(env, ISRB ? (MOVE_BOOST * -MOVE_INC) : -MOVE_INC);
	if (ISR->is_rotate_right)
		wolf_rotate(RC, _RAD(ISRB ? (ROT_BOOST * -ROT_INC) : -ROT_INC));
}

void		wolf_sdl_loop(t_env *env)
{
	bool	exit;

	exit = false;
	while (!exit)
	{
		while (SDL_PollEvent(&SEVENT) > 0)
		{
			if (SETYPE == SDL_QUIT)
				exit = true;
			if (SETYPE == SDL_KEYDOWN)
			{
				if (SEKEY == SDLK_ESCAPE)
					exit = true;
				add_keys_down(env);
			}
			if (SETYPE == SDL_KEYUP)
				add_keys_up(env);
			add_mouse_moves(env);
		}
		add_loop_isr(env);
		wolf_rendering_rc(env);
	}
	wolf_free(&env);
}
