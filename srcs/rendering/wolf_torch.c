/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_torch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 22:08:27 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/11 22:35:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_rendering_torch(t_torch *torch, Uint32 *win_pxls, uint8_t fog_freq)
{
	static uint8_t	old_torch_frame;
	static uint8_t	torch_frame;
	fpoint			torch_shift;
	point			tp;
	point			p;

	if (old_torch_frame != fog_freq)
	{
		torch_frame = ft_rand(MAX_TORCH - 1);
		old_torch_frame = fog_freq;
	}
	tp.y = -1;
	p.y = torch_shift.y;
	torch_shift = (fpoint){TORCH_SHIFT_Y, TORCH_SHIFT_X};
	while (WIN_Y > ++(p.y) && (tp.x = -1)
	&& torch->tex[torch_frame].surf->h > ++tp.y && (p.x = torch_shift.x))
		while (++p.x < WIN_X && ++tp.x < torch->tex[torch_frame].surf->w)
			if (!ft_is_one_of_n(torch->tex[torch_frame]
				.pixels[tp.y * torch->tex[torch_frame].surf->w + tp.x],
					2UL, 0xff000000L, 0x00L))
				win_pxls[p.y * WIN_X + p.x] = torch->tex[torch_frame]
					.pixels[tp.y * torch->tex[torch_frame].surf->w + tp.x];
}
