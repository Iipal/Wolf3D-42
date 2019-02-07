/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_defines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:34:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/07 10:56:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_DEFINES_H
# define WOLF3D_DEFINES_H

# define WIN_X		2000
# define WIN_Y		1000
# define WIN_TITTLE	"Wolfenstein 3D"

# define WIN_EXT	17
# define WIN_EXTM	(1L << 17)

# define MOUSE_MASK	0
# define MOUSE_DOWN	4
# define MOUSE_UP	5
# define MOUSE_MOVE	6

# define MLEFT_BUTTON	1
# define MRIGHT_BUTTON	2
# define MTHIRD_BUTTON	3
# define MSCROLL_DOWN	4
# define MSCROLL_UPS	5
# define MSCROLL_LEFT	6
# define MSCROLL_RIGHT	7

# define PI 3.141592

# define INT_MAX	2147483647
# define INT_MIN	(-INT_MAX-1)

# define SHIFT_INC	15

# define ROT_MIN	0.0
# define ROT_INC	5.0
# define ROT_MAX	360.0

# define ZOOM_INC	1
# define ZOOM_MIN	1
# define ZOOM_DEF	15
# define ZOOM_MAX	127

# define MAX_TEXTURES	1

# define _MSG(msg) ft_putstr(msg);
# define _MSGN(msg) ft_putendl(msg);
# define _NOTIS(msg, ex, do, ret) if (!(ex)) {_MSGN(msg);do;return (ret);}
# define _NOTIS_N(ex) if (!(ex)) return (NULL)
# define _NOTIS_F(ex) if (!(ex)) return (false)

# define _ISARGS(ac, av) {--ac;++av;_NOTIS(E_USAGE, !(ac != 1), exit(-1), 0);}

# define _ABS(var) ((var) < 0) ? -(var) : (var)
# define _RAD(deg) (((deg) * PI) / 180.0)
# define _COSR(angle) cos(_RAD(angle))
# define _SINR(angle) sin(_RAD(angle))

# define _FPOINT	typedef t_fp			fpoint
# define _POINT		typedef t_p				point
# define _BOOL		typedef enum e_bool		bool
# define _IARR		typedef int*			iarr
# define _ITAB		typedef int**			itab
# define _UINT		typedef unsigned int	uint

# define MPTR	env->mlx->mlx
# define WPTR	env->mlx->win
# define IPTR	env->mlx->img
# define SPTR	env->mlx->screen

# define MAPY	env->map->ysize
# define MAPX	env->map->xsize
# define MAP	env->map->tab

#endif
