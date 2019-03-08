/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:04:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/08 10:11:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "lft_str.h"
# include "lft_mem.h"
# include "lft_put.h"
# include "lft_ctype.h"

# include <stdarg.h>

# define BUFF_SIZE 2048

enum	e_bool {false, true} __attribute__((packed));

# define _BOOL  typedef enum e_bool bool

_BOOL;

int		ft_gnl(const int fd, char **line);
size_t	ft_rand(size_t limits);
bool	ft_is_one_of_n(long cmp, long n, ...);

#endif
