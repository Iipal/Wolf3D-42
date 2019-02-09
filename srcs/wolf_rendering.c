/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:03:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/09 12:37:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

#include <time.h>

typedef struct	s_ray_caster
{
	fpoint	pos;
	fpoint	dir;
	fpoint	plane;
	float	rotate;
}				t_rc;

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

void	wolf_rendering(t_env *env)
{
	srand(time(NULL));
	t_rc	*rc;

	rc = malloc(sizeof(t_rc));
	*rc = (t_rc){{0,0}, {0, -1}, {0.66, 0}, 0};
	add_randomize_pos(rc, env);
	printf("%.1f - %.1f\n", rc->pos.y, rc->pos.x);
}
