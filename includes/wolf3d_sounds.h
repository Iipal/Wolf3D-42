/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_sounds.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:29:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/12 15:15:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_SOUNDS_H
# define WOLF3D_SOUNDS_H

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
# define AMBIENT_BG     "resources/music/ambient_game_bg.wav"

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

#endif
