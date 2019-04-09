/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_defines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:34:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 20:00:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_DEFINES_H
# define WOLF3D_DEFINES_H

/*
**	Setups for MacOS\Linux
**	WIN_X, WIN_Y: Window size.
**	SELECTOR_X\Y: Main menu selector size.
**	MENU_BG: Main menu background textrue.
**
**	MacOS setup:
*/
# ifdef __APPLE__
#  define WIN_X 1500
#  define WIN_Y 750

#  define SELECTOR_X    150
#  define SELECTOR_Y    3

#  define SPOS_START    20
#  define SPOS_EXIT     90

#  define MENU_BG       "resources/main_menu/1500x750_menu_bg.bmp"
# endif

/*
**	Linux setup:
*/
# ifdef __linux__
#  define WIN_X 1000
#  define WIN_Y 500

#  define SELECTOR_X    100
#  define SELECTOR_Y    2

#  define SPOS_START    13
#  define SPOS_EXIT     60

#  define MENU_BG       "resources/main_menu/1000x500_menu_bg.bmp"
# endif

# include "wolf3d_macroses.h"
# include "wolf3d_textures.h"
# include "wolf3d_colors.h"
# include "wolf3d_sounds.h"
# include "wolf3d_flags.h"

/*
**	------------------------
**	Techinal game constants:
**	------------------------
*/

/*
**	File with game usage.
*/
# define USAGE_GAME_FILE     "resources/game.txt"

/*
**	File with flags usage.
*/
# define USAGE_FLAG_FILE     "resources/flags.txt"

/*
**	Default window title:
*/
# define WOLF_TITLE    "Wolfenstein 3D"

/*
**	Default wolf3d executable path.
**	Game process wolf3d can run only from project root folder.
*/
# define WOLF_EXE_PATH  "./wolf3d"

/*
**	Maps file required extension for correct reading.
*/
# define WOLF_FILE_EXT  ".w3d"

/*
**	---------------------------
**	Ingame important constants:
**	---------------------------
*/

/*
**	Constant for center ray dot display precision on minimap.
*/
# define MMAP_PRECISION 0.05f

/*
**	For FPS based correct movement multiply constant.
*/
# define MOVE_INC       2.0f

/*
**	Current FPS based movement value multiply to this constant
**	 for increase step value when player running.
*/
# define MOVE_BOOST     2.1f

/*
**	For FPS based correct rotate multiply constant.
*/
# define ROT_INC        90.00f

/*
**	Current FPS based rotate value multiply to this constant
**	 for increase rotate when player running.
*/
# define ROT_BOOST      1.8f

/*
**	Constant for correct rotate speed when use mouse for rotate player camera.
*/
# define ROT_MOUSE_INC  0.002f

/*
**	Delta time after what time torch frame & fog_dist will changed.
*/
# define REFRESH_TORCH_FOG_FREQ .33f

/*
**	Delta time for pause after what will played next step sound.
*/
# define REFRESH_STEP_SFX_FREQ  .33f

/*
**	Delta time for pause after what will played next step sound
**	 when player running.
*/
# define REFRESH_RUN_SFX_FREQ   .22f

/*
**	Delta time for pause after what will refreshed FPS\ms display info.
*/
# define REFRESH_FPS_COUNTER    .5f

/*
**	Blur effect default value.
*/
# define BLUR_DEF   5

/*
**	Maximum blur value.
*/
# define BLUR_MAX   50

/*
**	That value add\subtract when player changing blur value.
*/
# define BLUR_INC   1

/*
**	Minimum blur value.
*/
# define BLUR_MIN   3

#endif
