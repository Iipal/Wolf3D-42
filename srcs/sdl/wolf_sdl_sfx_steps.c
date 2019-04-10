/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_sdl_sfx_steps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 23:17:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/10 11:06:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_playing_steps(t_sfx *sfx, bool is_boost)
{
	static bool	lr_step;

	if ((is_boost ? REFRESH_RUN_SFX_FREQ : REFRESH_STEP_SFX_FREQ)
		< sfx->step_sfx_timeout.res)
	{
		lr_step ? Mix_PlayChannel(-1, sfx->lstep, 0)
				: Mix_PlayChannel(-1, sfx->rstep, 0);
		lr_step = !lr_step;
		sfx->step_sfx_timeout.res = 0;
	}
	else
	{
		sfx->step_sfx_timeout.old = sfx->step_sfx_timeout.current;
		sfx->step_sfx_timeout.current = SDL_GetTicks();
		sfx->step_sfx_timeout.res +=
			(sfx->step_sfx_timeout.current - sfx->step_sfx_timeout.old) / 1000;
	}
}
