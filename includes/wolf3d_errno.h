/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_errno.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:39:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/07 11:47:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_ERRNO_H
# define WOLF3D_ERRNO_H

# define E_USAGE	"Usage: ./wolf3d <map_name>.w3d"
# define E_ALLOC	"Where is memory, pal ?"
# define E_FILER	"File reading error"

# define E_EMAP		"\tERROR: Empty map \\ "
# define E_IMAP		"\tERROR: Invalid map \\ "
# define E_ENDMAP	"\tERROR: Where is the end ... ? \\ "
# define E_NOFLOOR	"\tERROR: The floor is lava ? \\ "

#endif
