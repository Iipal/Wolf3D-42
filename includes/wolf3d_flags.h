/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_flags.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:26:52 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/10 00:16:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_FLAGS_H
# define WOLF3D_FLAGS_H

/*
**	Flags counter.
*/
# define F_MAX              7

/*
**	Print help info about flags.
*/
# define F_HELP             "-help"

/*
**	Show debug FPS\ms info by default and turned off fog and sounds.
*/
# define F_DEBUG_INFO       "-dbg-info"

/*
**	Create window without borders.
*/
# define F_WIN_NO_BORDER    "-no-border"

/*
**	By default turned off all in-game sounds and music.
*/
# define F_NO_SOUND         "-no-sound"

/*
**  Turned off main menu screen on start.
*/
# define F_NO_MENU          "-no-menu"

/*
**  Turned off by default fog rendering.
*/
# define F_NO_FOG           "-no-fog"

/*
**  Turned on by default rotate player camera without left mouse click.
*/
# define F_ALWAYS_MOUSE     "-use-mouse"

/*
**  Short flag equals to -help.
*/
# define FS_HELP            "-h"

/*
**  Short flag equals to -dbg-info.
*/
# define FS_DEBUG_INFO      "-d"

/*
**  Short flag equals to -no-border.
*/
# define FS_WIN_NO_BORDER   "-nb"

/*
**  Short flag equals to -no-border.
*/
# define FS_NO_SOUND        "-ns"

/*
**  Short flag equals to -no-menu.
*/
# define FS_NO_MENU         "-nm"

/*
**  Short flag equals to -no-fog.
*/
# define FS_NO_FOG          "-nf"

/*
**  Short flag equals to -dbg-info.
*/
# define FS_ALWAYS_MOUSE    "-um"

#endif
