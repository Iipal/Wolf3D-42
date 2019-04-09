/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_macroses.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:32:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 16:32:54 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_MACROSES_H
# define WOLF3D_MACROSES_H

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
