/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_sfx_steps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 23:17:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/07 11:04:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wolf_playing_steps(t_sfx *sfx, bool is_boost)
{
	static bool	lr_step;

	if (sfx->step_sfx_timeout.res_time > (is_boost ? REFRESH_RUN_SFX_FREQ
							: REFRESH_STEP_SFX_FREQ))
	{
		lr_step ? Mix_PlayChannel(-1, sfx->lstep, 0)
			: Mix_PlayChannel(-1, sfx->rstep, 0);
		lr_step = !lr_step;
		sfx->step_sfx_timeout.res_time = 0;
	}
	else
	{
		sfx->step_sfx_timeout.old_time = sfx->step_sfx_timeout.current_time;
		sfx->step_sfx_timeout.current_time = SDL_GetTicks();
		sfx->step_sfx_timeout.res_time += (sfx->step_sfx_timeout.current_time
			- sfx->step_sfx_timeout.old_time) / 1000;
	}
}
