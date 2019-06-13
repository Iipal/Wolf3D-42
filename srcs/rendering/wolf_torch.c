/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_torch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 22:08:27 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/13 09:46:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_rendering_torch(t_torch *torch, Uint32 *win_pxls, uint8_t fog_freq)
{
	static uint8_t	old_torch_frame;
	static uint8_t	torch_frame;
	const point		torch_shift = {TORCH_SHIFT_Y, TORCH_SHIFT_X};
	uint32_t		curr_tex_pxl;
	point			p;

	if (old_torch_frame != fog_freq)
	{
		torch_frame = ft_rand(MAX_TORCH - 1);
		old_torch_frame = fog_freq;
	}
	p.y = -1;
	while (torch->tex[torch_frame].surf->h > ++p.y && (p.x = -1))
		while (torch->tex[torch_frame].surf->w > ++p.x)
		{
			curr_tex_pxl = torch->tex[torch_frame]
				.pixels[p.y * torch->tex[torch_frame].surf->w + p.x];
			if (curr_tex_pxl != 0xff000000 || curr_tex_pxl != 0x00)
				if (WIN_Y > p.y + torch_shift.y && WIN_X > p.x + torch_shift.x)
					win_pxls[(p.y + torch_shift.y)
						* WIN_X + (p.x + torch_shift.x)] = curr_tex_pxl;
		}
}
