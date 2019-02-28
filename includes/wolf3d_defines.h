/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_defines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:34:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/28 11:45:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_DEFINES_H
# define WOLF3D_DEFINES_H

# ifdef __APPLE__
#  define WIN_X 1500
#  define WIN_Y 750

#  define SELECTOR_X    250
#  define SELECTOR_Y    3

#  define MENU_BG   "resources/main_menu/1500x750_menu_bg.bmp"
# endif

# ifdef __linux__
#  define WIN_X 1000
#  define WIN_Y 500

#  define MENU_BG   "resources/main_menu/1000x500_menu_bg.bmp"
# endif

# define WOLF_TITTLE    "Wolfenstein 3D"
# define WOLF_EXE_PATH  "./wolf3d"
# define WOLF_FILE_EXT	".w3d"

# define IRGB_BLACK     0x00
# define IRGB_MAP_RAY   0x00B37A
# define IRGB_MAP_POS   0xC7C7C7
# define IRGB_MAP_BG    0x808080
# define IRGB_SKY       0x002D80
# define IRGB_FLOOR     0x242424
# define IRGB_COLORS    8
# define IRGB_WHITE     0xFFFFFF
# define IARGB_WHITE    0xFFFFFFFF
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
# define ROT_INC        90.00f
# define ROT_BOOST      1.8f
# define ROT_MOUSE_INC  0.002f
# define MMAP_PRECISION 0.05f

# define MAX_FOG_DIST   4.2

# define REFRESH_TORCH_FOG_FREQ .33f

# define TORCH_SHIFT_X      ((WIN_X + TORCH->tex[torch_frame].surf->w) / 1.6)
# define TORCH_SHIFT_Y      (WIN_Y - TORCH->tex[torch_frame].surf->h)
# define SELECTOR_START_X   ((WIN_X - SELECTOR_X) / 2.0)
# define SELECTOR_START_Y   ((WIN_Y - SELECTOR_Y) / 2.0)

# define MAX_TEXTURES   8
# define TEXWALL1       "resources/wall_textures/wall1.bmp"
# define TEXWALL2       "resources/wall_textures/wall2.bmp"
# define TEXWALL3       "resources/wall_textures/wall3.bmp"
# define TEXWALL4       "resources/wall_textures/wall4.bmp"
# define TEXWALL5       "resources/wall_textures/wall5.bmp"
# define TEXWALL6       "resources/wall_textures/wall6.bmp"
# define TEXWALL7       "resources/wall_textures/wall7.bmp"
# define TEXWALL8       "resources/wall_textures/wall8.bmp"
# define TEXFLOOR       "resources/floor_and_sky/floor.bmp"
# define TEXSKY         "resources/floor_and_sky/sky.bmp"
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
# define _IS(ex, do, ret) if (ex) {do; return (ret);}
# define _ISM(msg, ex, do, ret) if (ex) {_MSGN(msg);do;return (ret);}
# define _IS_N(ex) if (ex) return (NULL)
# define _IS_F(ex) if (ex) return (false)

# define _FREE(trash, del)	if ((trash)) {del(trash); trash = NULL;}

# define PI 3.141592
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
# define _FNPTR     typedef void (*fn_selector)(t_env*)

# define SWIN   env->sdl->win
# define SWINS  env->sdl->win_surface
# define SWINP  env->sdl->win_pixels
# define SEVENT env->sdl->event
# define SETYPE env->sdl->event.type
# define SEKEY  env->sdl->event.key.keysym.sym

# define MAPY   env->map->ysize
# define MAP    env->map->tab
# define MAPC   env->map->colors

# define ISRT   env->isr->is_textured
# define ISRF   env->isr->is_render_fog

# define RC     env->rc

# define FOG    env->fog

# define POS    h->ftex.y * XTEX + h->ftex.x

#endif
