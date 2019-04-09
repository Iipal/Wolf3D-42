/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_errno.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:39:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 12:30:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_ERRNO_H
# define WOLF3D_ERRNO_H

# define E_USAGE    "Usage: ./wolf3d [flags ...] <map_name>.w3d"

# define E_OPEN     " ERROR: Cannot open usage file."

# define E_IFLAG    " ERROR: Invalid command line option."

# define E_DIR      " ERROR: Invalid executable path."
# define E_ALLOC    " ERROR: Where is memory, pal ?"
# define E_FILER    " ERROR: Invalid file."
# define E_IMAP     " ERROR: Invalid map."
# define E_EMAP     " ERROR: Empty map."
# define E_ENDMAP   E_IMAP " Where is the end ... ?"
# define E_NOFLOOR  E_IMAP " The floor is Java ?"

#endif
