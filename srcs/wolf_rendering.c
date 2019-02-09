/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:03:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/09 13:26:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	add_randomize_pos(t_rc *rc, t_env *env)
{
	while (1)
	{
		rc->pos = (fpoint){rand() % MAPY, rand() % MAPX};
		if (MAP[(int)rc->pos.y][(int)rc->pos.x].rgb == IRGB_WHITE
			&& MAP[(int)rc->pos.y][(int)rc->pos.x].rgb == IRGB_WHITE)
			break ;
	}
}

void		wolf_rendering(t_env *env)
{
	t_rc	rc;

	srand(time(NULL));
	rc = (t_rc){{0, 0}, {0, -1}, {0.66, 0}, 0};
	add_randomize_pos(&rc, env);
	printf("%.1f - %.1f\n", rc.pos.y, rc.pos.x);
}
