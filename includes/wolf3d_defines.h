/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_defines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:34:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 11:34:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_DEFINES_H
# define WOLF3D_DEFINES_H

# include "wolf3d_textures.h"

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

/*
**	----------------------
**	Flags constant values:
**	----------------------
*/

/*
**	F_MAX: Flags counter.
*/
# define F_MAX              2

/*
**	Print help info about flags.
*/
# define F_HELP             "-h"

/*
**	Create window without borders.
*/
# define F_WIN_NO_BORDER    "-no-border"

/*
**	-----------------------------
**	Game sound effects constants:
**	-----------------------------
*/

/*
**	Sound when window opened.
*/
# define MSTART         "resources/music/start.wav"

/*
**	Menu selector sound.
*/
# define MSELECTOR      "resources/music/selector.wav"

/*
**	Menu selector error sound.
*/
# define MSERROR        "resources/music/selector_err.wav"

/*
**	Game background music.
*/
# define AMBIENT_BG     "resources/music/ambient_game_bg.mp3"

/*
**	When player walking, left step sound.
*/
# define GAME_LSTEP     "resources/music/lstep.wav"

/*
**	When player walking, right step sound.
*/
# define GAME_RSTEP     "resources/music/rstep.wav"

/*
**	In menu backgound music volume divided by this value.
*/
# define BG_VOL_MUTE    3

/*
**	Default background music volume value.
*/
# define BG_VOL_DEF     60

/*
**	Maximum background music volume.
*/
# define BG_VOL_MAX     100

/*
**	Minimum background music volume.
*/
# define BG_VOL_MIN     10

/*
**	That value add\subtract when player changing background music volume.
*/
# define BG_VOL_INC     5

/*
**	------------------------
**	Techinal game constants:
**	------------------------
*/

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
**	----------------------
**	Color constant values:
**	----------------------
*/

/*
**	RayCating center ray dot color on minimap.
**	(Light Green hexadecimal color)
*/
# define RGB_MAP_RAY   0x00B37A

/*
**	RayCating player dot color on minimap.
**	(Whitesmoke hexadecimal color)
*/
# define RGB_MAP_POS   0xC7C7C7

/*
**	RayCating wall borders color on minimap.
**	(Whitesmoke hexadecimal color)
*/
# define RGB_MAP_BG    0x808080

/*
**	One of fog colors.
**	Screen fill color for correct re-drawing.
**	(Black hexadecimal color)
*/
# define RGB_BLACK     0x00

/*
**	Sky color.
**	(Darkest Blue hexadecimal color)
*/
# define RGB_SKY       0x002D80

/*
**	Floor color.
**	(Gray hexadecimal color)
*/
# define RGB_FLOOR     0x242424

/*
**	Wall colors counter.
*/
# define RGB_COLORS    8

/*
**	One of wall colors.
**	One of fog colors.
**	(White hexadecimalcolor)
*/
# define RGB_WHITE     0xFFFFFF

/*
**	One of wall colors.
**	One of fog colors.
**	(Red hexadecimal color)
*/
# define RGB_RED       0xF21856

/*
**	One of wall colors.
**	One of fog colors.
**	(Orange hexadecimal color)
*/
# define RGB_ORANGE    0xFFB833

/*
**	One of wall colors.
**	One of fog colors.
**	(Lime hexadecimal color)
*/
# define RGB_LIME      0x7FFF00

/*
**	One of wall colors.
**	One of fog colors.
**	(Aqua hexadecimal color)
*/
# define RGB_AQUA      0x6EFDFF

/*
**	One of wall colors.
**	One of fog colors.
**	(Purple hexadecimal color)
*/
# define RGB_PURPLE    0xD800F0

/*
**	One of wall colors.
**	One of fog colors.
**	(Mint hexadecimal color)
*/
# define RGB_MINT      0x2BFFE3

/*
**	One of wall colors.
**	One of fog colors.
**	(Dark blue hexadecimal color)
*/
# define RGB_DARK_BLUE 0x2B75FF

/*
**	"Side" wall mix color for "light effects".
**	(Light Gray hexadecimal color)
*/
# define FCL            0x7F7F7F

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

/*
**	--------------------
**	All useful Macroses:
**	--------------------
*/

/*
**	Shift torch textures by X for correct display in right down corner.
*/
# define TORCH_SHIFT_X      ((WIN_X + TORCH->tex[torch_frame].surf->w) / 1.6)

/*
**	Shift torch textures by Y for correct display in right down corner.
*/
# define TORCH_SHIFT_Y      (WIN_Y - TORCH->tex[torch_frame].surf->h)

/*
**	Main menu selector shift by X for correct display in center.
*/
# define SELECTOR_START_X   ((WIN_X - SELECTOR_X) / 2.0)

/*
**	Main menu selector shift by Y for correct display in center.
*/
# define SELECTOR_START_Y   ((WIN_Y - SELECTOR_Y) / 2.0)

/*
**	Used for validate argmunets count;
**	\param ac: Arguments counter.
**	\param av: Arguments array.
*/
# define ISARGS(ac, av) {--ac;++av; NOTIS(E_USAGE, ac, exit(-1), 0);}

/*
**	If \param ex true:
**	 \param do something.
*/
# define IFDO(ex, do) if ((ex)) { do; }

/*
**	Print \param msg to stdout.
*/
# define MSG(msg) ft_putstr(msg)

/*
**	Print \param msg to stdout followed by newline at end.
*/
# define MSGN(msg) ft_putendl(msg)

/*
**	If \param ex false:
**	 Print \param msg followed by newline at end.
**	 \param do something.
**	 \param ret return value.
*/
# define NOTIS(msg, ex, do, ret) if (!(ex)) {MSGN(msg);do;return(ret);}

/*
**	If \param ex false:
**	 Print \param msg followed by newline at end.
**	 \param do1 something.
**	 \param do2 something.
*/
# define NOTIS2(msg, ex, do1, do2) if (!(ex)) {MSGN(msg);do1;do2;}

/*
**	If \param ex false return false.
*/
# define NOTIS_F(ex) if (!(ex)) return (false)

/*
**	If \param ex true:
**	 \param do something.
**	 \param ret return value.
*/
# define IS(ex, do, ret) if ((ex)) {do; return (ret);}

/*
**	If \param ex true:
**	 Print \param msg followed by newline at end.
**	 \param do something.
**	 \param ret return value.
*/
# define ISM(msg, ex, do, ret) if ((ex)) {MSGN(msg);do;return (ret);}

/*
**	If \param ex true return false.
*/
# define IS_F(ex) if ((ex)) return (false)

/*
**	Called ft_bzero(\param dest, size of \param type multiply by \param x).
*/
# define Z(type, dest, x) ft_bzero(dest, sizeof(type) * (x))

/*
**	Allocating memroy and set all values to zero by calling Z macros.
**	 \param t data type.
**	 \param d destination variable.
**	 \param x counter how much \param t memory needed to allocate.
*/
# define ISZ(t, d, x) NOTIS_F(d = (t*)malloc(sizeof(t)*(x))); Z(t, d, x)

/*
**	If \param trash isnt NULL:
**	 Free memory with \param del function call.
**	 And set \param trash to NULL.
*/
# define FREE(trash, del) if ((trash)) {del(trash); trash = NULL;}

/*
**	--------------
**	Math macroses:
**	--------------
*/

/*
**	Pi value.
*/
# define PI 3.141592

/*
**	Absolute value of \param var macros.
*/
# define ABS(var) ((var) < 0) ? -(var) : (var)

/*
**	Convert \param deg value from degrees to radians.
*/
# define RAD(deg) (((deg) * PI) / 180.0)

/*
** Lesser value among the two.
*/
# define MIN(a,b) (((a)<(b))?(a):(b))

/*
** Greatest value among the two.
*/
# define MAX(a,b) (((a)>(b))?(a):(b))

/*
**	----------------------------------------------------
**	Typedef macroses for above the school-42 code norme:
**	----------------------------------------------------
*/

# define FPOINT     typedef struct s_fpoint fpoint
# define POINT      typedef struct s_point  point
# define IARR       typedef int32_t*        iarr
# define ITAB       typedef int32_t**       itab
# define UIARR      typedef uint32_t*       uiarr
# define UINT       typedef uint32_t        uint
# define FCOLOR     typedef struct s_fcolor FColor

# define FPTR_FLG   typedef void (*f_fnptr)(t_env*, char**, int32_t)

/*
**	"Shortcut" macroses for variables in structures
*/

# define SWIN   env->sdl->win
# define SWINP  env->sdl->win_pixels
# define SEVENT env->sdl->event
# define SEKEY  env->sdl->event.key.keysym.sym
# define MAPY   env->map->size.y
# define MAP    env->map->tab
# define MAPC   env->map->colors
# define RC     env->rc

#endif
