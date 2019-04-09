/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_errno.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:39:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 12:41:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_ERRNO_H
# define WOLF3D_ERRNO_H

/*
**  Printed this message if not enought command line arguments for start game.
*/
# define E_USAGE    "Usage: ./wolf3d [flags ...] <map_name>.w3d"

/*
**  Printed this message if cannot open usage file.
*/
# define E_OPEN     " ERROR: Cannot open usage file."

/*
**  Printed this message if one of flags is invalid.
*/
# define E_IFLAG    " ERROR: Invalid command line option."

/*
**  Printed this message if user trying to start game not from root folder.
*/
# define E_DIR      " ERROR: Invalid executable path."

/*
**  Printed this mesage if allocating memory is failed.
*/
# define E_ALLOC    " ERROR: Where is memory, pal ?"

/*
**  Printed this message if map file is invalid or doesnt exits.
*/
# define E_FILER    " ERROR: Invalid file."

/*
**  Printed this message if map is invalid.
*/
# define E_IMAP     " ERROR: Invalid map."

/*
**  Printed this message if map is empty.
*/
# define E_EMAP     " ERROR: Empty map."

/*
**  Printed this message if map hasnt border walls.
*/
# define E_ENDMAP   E_IMAP " Where is the end ... ?"

/*
**  Printed this message if on map doesnt exist any 0 for player place.
*/
# define E_NOFLOOR  E_IMAP " The floor is Java ?"

#endif
