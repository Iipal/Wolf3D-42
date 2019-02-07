/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:03:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/07 20:08:45 by tmaluh           ###   ########.fr       */
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
		if (!MAP[(int)rc->pos.y][(int)rc->pos.x])
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
	for (int x = 0; x < WIN_X; x++)
	{
		double	camX = 2 * x / (double)WIN_X - 1;
		double	rayDirX = rc->dir.x + rc->plane.x * camX;
		double	rayDirY = rc->dir.y + rc->plane.y * camX;
		int		mapX = (int)rc->pos.x;
		int		mapY = (int)rc->pos.y;
		double	sideDistX;
		double	sideDistY;
		double	deltaDistX = _ABS(1 / rayDirX);
		double	deltaDistY = _ABS(1 / rayDirY);
		double	perpWallDist;
		int		stepX;
		int		stepY;
		int		hit = 0;
		int		side;
		
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (rc->pos.x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - rc->pos.x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (rc->pos.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - rc->pos.y) * deltaDistY;
		}

		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (MAP[mapX][mapY] > 0)
				hit = 1;
		}
		if (!side)
			perpWallDist = (mapX - rc->pos.x + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - rc->pos.y + (1 - stepY) / 2) / rayDirY;
		int	lineH = (int)(WIN_Y / perpWallDist);
		int	drawStart = -lineH / 2 + WIN_Y / 2;
		if (drawStart < 0)
			drawStart = 0;
		int	drawEnd = lineH / 2 + WIN_X / 2;
		if (drawEnd >= WIN_Y)
			drawEnd = WIN_Y - 1;
		SPTR[drawStart * WIN_X + drawEnd] = IRGB_PURPLE;
	}
	mlx_put_image_to_window(MPTR, WPTR, IPTR, 0, 0);
	printf("%.1f - %.1f\n", rc->pos.y, rc->pos.x);
}
