/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:03:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/07 11:12:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

#include <time.h>

typedef struct	s_ray_caster
{
	point	pos;
	float	rotate;
}				t_rc;

static void	add_randomize_pos(t_rc *rc, t_env *env)
{
	while (1)
	{
		rc->pos = (point){rand() % MAPY, rand() % MAPX};
		if (!MAP[rc->pos.y][rc->pos.x])
			break ;
	}
}

void	wolf_rendering(t_env *env)
{
	srand(time(NULL));
	t_rc	*rc;

	rc = malloc(sizeof(t_rc));
	*rc = (t_rc){{0,0},0};
	add_randomize_pos(rc, env);
	printf("%d - %d\n", rc->pos.y, rc->pos.x);
}
