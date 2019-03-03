/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_sdl_rendering_loop.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 22:59:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/03 22:10:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_keys_press(t_env *env, bool *exit)
{
	(SEKEY == SDLK_ESCAPE) ? (*exit = true) : 0;
	if (SEKEY == SDLK_w || SEKEY == SDLK_UP)
		env->isr->is_move_forward = true;
	if (SEKEY == SDLK_a || SEKEY == SDLK_LEFT)
		env->isr->is_rotate_left = true;
	if (SEKEY == SDLK_s || SEKEY == SDLK_DOWN)
		env->isr->is_move_backward = true;
	if (SEKEY == SDLK_d || SEKEY == SDLK_RIGHT)
		env->isr->is_rotate_right = true;
	if (SEKEY == SDLK_f)
		env->isr->is_render_fog = !env->isr->is_render_fog;
	if (SEKEY == SDLK_m)
		env->isr->is_draw_minimap = !env->isr->is_draw_minimap;
	(SEKEY == SDLK_LSHIFT) ? (env->isr->is_boost_step = true) : 0;
	(SEKEY == SDLK_t) ? (env->isr->is_textured = !env->isr->is_textured) : 0;
	if (SEKEY == SDLK_c)
		env->fog.fog_color = wolf_fog_change(&(env->fog.clr));
}

static void	add_keys_release(t_env *env)
{
	if (SEKEY == SDLK_w || SEKEY == SDLK_UP)
		env->isr->is_move_forward = false;
	if (SEKEY == SDLK_a || SEKEY == SDLK_LEFT)
		env->isr->is_rotate_left = false;
	if (SEKEY == SDLK_s || SEKEY == SDLK_DOWN)
		env->isr->is_move_backward = false;
	if (SEKEY == SDLK_d || SEKEY == SDLK_RIGHT)
		env->isr->is_rotate_right = false;
	(SEKEY == SDLK_LSHIFT) ? (env->isr->is_boost_step = false) : 0;
}

static void	add_mouse_moves(t_env *env)
{
	SDL_GetMouseState(&(env->sdl->event.motion.x), &(env->sdl->event.motion.y));
	if (env->sdl->event.type == SDL_MOUSEBUTTONDOWN)
		env->mouse->is_pressed_mouse = true;
	if (env->sdl->event.type == SDL_MOUSEBUTTONUP)
		env->mouse->is_pressed_mouse = false;
	env->mouse->last = env->mouse->curr;
	env->mouse->curr = env->sdl->event.motion.x;
	if (env->mouse->is_pressed_mouse)
		wolf_rotate(env->rc, -(env->sdl->event.motion.x -
			env->mouse->last) * ROT_MOUSE_INC);
}

static void	add_loop_isr(t_env *env)
{
	if (env->isr->is_move_forward)
		wolf_move(env, env->isr->is_boost_step
			? (MOVE_BOOST * env->fps.move) : env->fps.move);
	if (env->isr->is_rotate_left)
		wolf_rotate(env->rc, _RAD(env->isr->is_boost_step
			? (ROT_BOOST * env->fps.rot) : env->fps.rot));
	if (env->isr->is_move_backward)
		wolf_move(env, env->isr->is_boost_step
			? (MOVE_BOOST * -env->fps.move) : -env->fps.move);
	if (env->isr->is_rotate_right)
		wolf_rotate(env->rc, _RAD(env->isr->is_boost_step
			? (ROT_BOOST * -env->fps.rot) : -env->fps.rot));
}

void		wolf_sdl_rendering_loop(t_env *env)
{
	bool	exit;

	exit = false;
	while (!exit)
	{
		while (SDL_PollEvent(&env->sdl->event) > 0)
		{
			(env->sdl->event.type == SDL_QUIT) ? (exit = true) : 0;
			if (env->sdl->event.type == SDL_KEYDOWN)
				add_keys_press(env, &exit);
			if (env->sdl->event.type == SDL_KEYUP)
				add_keys_release(env);
			add_mouse_moves(env);
		}
		add_loop_isr(env);
		wolf_rendering_rc(env);
	}
	Mix_FadeOutMusic(MUSIC_FADE_OUT);
}
