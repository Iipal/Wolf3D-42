/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_defines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:34:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/20 10:12:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_DEFINES_H
# define WOLF3D_DEFINES_H

# define WIN_TITTLE     "Wolfenstein 3D"

# define WOLF_FILE_EXT	".w3d"

# define MAX_FOG_DIST   4.2

# define TORCH_SHIFT_X  ((WIN_X + TORCH[torch_frame].surf->w) / 1.6)
# define TORCH_SHIFT_Y  (WIN_Y - TORCH[torch_frame].surf->h)

# define IRGB_BLACK     0x00
# define IRGB_MAP_RAY   0x00B37A
# define IRGB_MAP_POS   0xC7C7C7
# define IRGB_MAP_BG    0x808080
# define IRGB_SKY       0x002D80
# define IRGB_FLOOR     0x242424
# define IRGB_COLORS    8
# define IRGB_WHITE     0xFFFFFF
# define IRGB_RED       0xF21856
# define IRGB_ORANGE    0xFFB833
# define IRGB_LIME      0x7FFF00
# define IRGB_AQUA      0x6EFDFF
# define IRGB_PURPLE    0xD800F0
# define IRGB_MINT      0x2BFFE3
# define IRGB_DARK_BLUE 0x2B75FF

# define FCL            0x7F7F7F

# define MOVE_INC       2.0f
# define MOVE_BOOST     2.1f
# define ROT_INC        65.00f
# define ROT_BOOST      1.8f
# define ROT_MOUSE_INC  0.002f
# define MMAP_PRECISION 0.05f

# define MAX_TEXTURES   8
# define TEXWALL1       "resources/wall1.bmp"
# define TEXWALL2       "resources/wall2.bmp"
# define TEXWALL3       "resources/wall3.bmp"
# define TEXWALL4       "resources/wall4.bmp"
# define TEXWALL5       "resources/wall5.bmp"
# define TEXWALL6       "resources/wall6.bmp"
# define TEXWALL7       "resources/wall7.bmp"
# define TEXWALL8       "resources/wall8.bmp"
# define TEXFLOOR       "resources/floor.bmp"
# define TEXSKY         "resources/sky.bmp"
# define TFLOOR         MAX_TEXTURES
# define TSKY           TFLOOR + 1
# define YTEX           64
# define XTEX           64
# define TEX            env->textures
# define MAX_TORCH      6
# define TORCH1         "resources/torch/torch1.bmp"
# define TORCH2         "resources/torch/torch2.bmp"
# define TORCH3         "resources/torch/torch3.bmp"
# define TORCH4         "resources/torch/torch4.bmp"
# define TORCH5         "resources/torch/torch5.bmp"
# define TORCH6         "resources/torch/torch6.bmp"
# define TORCH          env->torch

# define _ISARGS(ac, av) {--ac;++av;_NOTIS(E_USAGE, !(ac != 1), exit(-1), 0);}

# define _MSG(msg) ft_putstr(msg);
# define _MSGN(msg) ft_putendl(msg);
# define _NOTIS(msg, ex, do, ret) if (!(ex)) {_MSGN(msg);do;return (ret);}
# define _NOTIS_N(ex) if (!(ex)) return (NULL)
# define _NOTIS_F(ex) if (!(ex)) return (false)

# define _FREE(trash, del)	if ((trash)) {del(trash); trash = NULL;}

# define PI             3.141592
# define _ABS(var) ((var) < 0) ? -(var) : (var)
# define _RAD(deg) (((deg) * PI) / 180.0)
# define _COSR(angle) cos(_RAD(angle))
# define _SINR(angle) sin(_RAD(angle))

# define _FPOINT    typedef t_fp                fpoint
# define _POINT     typedef t_p                 point
# define _IARR      typedef int*                iarr
# define _ITAB      typedef int**               itab
# define _UIARR     typedef unsigned int*       uiarr
# define _UINT      typedef unsigned int        uint
# define _ULL       typedef unsigned long long  ull

# define SWIN   env->sdl->win
# define SWINS  env->sdl->win_surface
# define SWINP  env->sdl->win_pixels
# define SEVENT env->sdl->event
# define SETYPE env->sdl->event.type
# define SEKEY  env->sdl->event.key.keysym.sym

# define MAPY   env->map->ysize
# define MAPX   env->map->xsize
# define MAP    env->map->tab
# define MAPC   env->map->colors

# define ISR    env->isr
# define ISRB   env->isr->is_boost_step
# define ISRT   env->isr->is_textured
# define ISRMM  env->isr->is_draw_minimap
# define ISRF   env->isr->is_render_fog

# define MOUSE  env->mouse

# define RC     env->rc

# define FPS    env->fps

#endif
