/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_rendering_colored.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:22:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/14 19:02:21 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int	add_correct_color(int texture_num)
{
	const int	colors[] = {IRGB_WHITE, IRGB_RED, IRGB_ORANGE, IRGB_LIME,
							IRGB_AQUA, IRGB_PURPLE, IRGB_MINT, IRGB_DARK_BLUE};
	int			i;

	i = -1;
	while (++i < MAX_TEXTURES)
		if (i == texture_num)
			return (colors[i]);
	return (0);
}

static int	add_choose_current_color(t_env *env)
{
	int	tex;
	int	temp;

	temp = MAP[RC->map.y][RC->map.x];
	if (RC->step.x < 0)
		tex = 0;
	else
		tex = -1;
	if (RC->is_side)
	{
		if (RC->step.y < 0)
			tex = 1;
		else
			tex = 2;
	}
	if (tex == 0)
		return (MAPC[RC->map.y][RC->map.x]);
	if (tex == -1)
		return (MAPC[RC->map.y][RC->map.x] / 2);
	if ((temp += tex) > MAX_TEXTURES)
		temp -= MAX_TEXTURES;
	return (add_correct_color(temp));
}

void		wolf_render_colored(t_env *env, point *p)
{
	int	current_color;

	current_color = add_choose_current_color(env);
	if (RC->is_side)
		current_color /= 2;
	p->y = RC->draw_start;
	while (p->y <= RC->draw_end)
		SPTR[(p->y)++ * WIN_X + p->x] = current_color;
}

void		wolf_fill_floor_if_colored_rc(iarr screen)
{
	point	p;

	p.y = -1;
	while (++(p.y) < WIN_Y && (p.x = -1))
		while (++(p.x) < WIN_X)
			screen[p.y * WIN_X + p.x] =
				(p.y >= WIN_Y / 2) ? IRGB_FLOOR : IRGB_SKY;
}
