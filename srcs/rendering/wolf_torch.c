/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_torch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 22:08:27 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 00:35:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_rendering_torch(t_env *env)
{
	static uint8_t	old_torch_frame;
	static uint8_t	torch_frame;
	const fpoint	torch_shift = {TORCH_SHIFT_Y, TORCH_SHIFT_X};
	point			p;
	point			tp;

	if (old_torch_frame != FOG.freq)
	{
		torch_frame = ft_rand(MAX_TORCH - 1);
		old_torch_frame = FOG.freq;
	}
	tp.y = -1;
	p.y = torch_shift.y;
	while (++(p.y) < WIN_Y && ++(tp.y) < env->torch->tex[torch_frame].surf->h
		&& (tp.x = -1)
		&& (p.x = torch_shift.x))
		while (++(p.x) < WIN_X
			&& ++(tp.x) < env->torch->tex[torch_frame].surf->w)
			if (!(ft_is_one_of_n(env->torch->tex[torch_frame].pixels[
				tp.y * env->torch->tex[torch_frame].surf->w + tp.x],
				2, (long)0xff000000, (long)0x00)))
				env->sdl->win_pixels[p.y * WIN_X + p.x] =
					env->torch->tex[torch_frame].pixels[tp.y * env->torch->tex[
						torch_frame].surf->w + tp.x];
}
