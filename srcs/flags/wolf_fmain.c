/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_fmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 00:02:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/10 11:23:33 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline void	wolf_fdebug_info(t_env *env, strtab av, int32_t ac)
{
	wolf_fno_sound(env, av, ac);
	wolf_no_fog(env, av, ac);
	env->isr->is_render_fps = true;
	env->isr->is_render_minimap = false;
}

inline void	wolf_fno_sound(t_env *env, strtab av, int32_t ac)
{
	(void)av;
	(void)ac;
	env->isr->is_play_music = false;
	env->isr->is_play_steps = false;
}

inline void	wolf_fno_menu(t_env *env, strtab av, int32_t ac)
{
	(void)av;
	(void)ac;
	env->isr->is_no_main_menu = true;
}

inline void	wolf_no_fog(t_env *env, strtab av, int32_t ac)
{
	(void)av;
	(void)ac;
	env->isr->is_render_fog = false;
}

inline void	wolf_ftex_sides_of_world(t_env *env, strtab av, int32_t ac)
{
	(void)av;
	(void)ac;
	env->isr->is_world_sides_textures = true;
}
