/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:03:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/13 12:53:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wolf_render_textured(t_env *env, point *p)
{
	int		d;
	int		current_texture;
	int		current_color;
	point	tex_pos;
	float	where_is_hit;

	current_texture = MAP[RC->map.y][RC->map.x] - 1;
	if (!RC->is_side)
		where_is_hit = RC->pos.y + RC->pwd * RC->ray_dir.y;
	else
		where_is_hit = RC->pos.x + RC->pwd * RC->ray_dir.x;
	where_is_hit -= floor(where_is_hit);
	tex_pos.x = (int)(where_is_hit * (double)(XTEX));
	if (!RC->is_side && RC->ray_dir.x > 0)
		tex_pos.x = XTEX - tex_pos.x - 1;
	if (RC->is_side && RC->ray_dir.y > 0)
		tex_pos.x = XTEX - tex_pos.x - 1;
	p->y = RC->draw_start;
	while (p->y < RC->draw_end)
	{
		d = p->y * 256 - WIN_Y * 128 + RC->hline * 128;
		tex_pos.y = ((d * YTEX) / RC->hline) / 256;
		current_color = TEX[current_texture].img[tex_pos.y * YTEX + tex_pos.x];
		if (RC->is_side)
			current_color = (current_color >> 1) & 8355711;
		SPTR[(p->y)++ * WIN_X + p->x] = current_color;
	}
}

void	wolf_render_colored(t_rc *rc, iarr screen, itab colors, point *p)
{
	int	current_color;

	current_color = colors[rc->map.y][rc->map.x];
	if (rc->is_side)
		current_color /= 2;
	p->y = rc->draw_start;
	while (p->y <= rc->draw_end)
		screen[(p->y)++ * WIN_X + p->x] = current_color;
}

void		wolf_rendering_rc(t_env *env)
{
	point	p;

	ft_bzero(SPTR, sizeof(int) * WIN_X * WIN_Y);
	p.y = -1;
	while (++(p.y) < WIN_Y && (p.x = -1))
		while (++(p.x) < WIN_X)
			SPTR[p.y * WIN_X + p.x] = (p.y >= WIN_Y / 2)
								? IRGB_GRAY : 0;
	p.x = -1;
	while (++(p.x) < WIN_X)
	{
		*(RC) = (t_rc){{RC->pos.y, RC->pos.x}, {RC->dir.y, RC->dir.x},
		{RC->plane.y, RC->plane.x}, 0, {0, 0}, {0, 0}, {0, 0}, {0, 0},
		0, {0, 0}, false, false, 0, 0, 0};
		RC->xcamera = 2 * p.x / (double)WIN_X - 1;
		RC->ray_dir = (fpoint){RC->dir.y + RC->plane.y * RC->xcamera,
			RC->dir.x + RC->plane.x * RC->xcamera };
		RC->map = (point){(int)RC->pos.y, (int)RC->pos.x};
		RC->absdist = (fpoint){_ABS(1 / RC->ray_dir.y),
			_ABS(1 / RC->ray_dir.x)};
		wolf_set_diststep(RC);
		wolf_check_hit(RC, MAP);
		wolf_set_draw_area(RC);
		ISRT ? wolf_render_textured(env, &p)
			: wolf_render_colored(RC, SPTR, MAPC, &p);
	}
	mlx_put_image_to_window(MPTR, WPTR, IPTR, 0, 0);
}
