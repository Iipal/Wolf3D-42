/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_colors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:30:05 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 16:30:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_COLORS_H
# define WOLF3D_COLORS_H

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

#endif
