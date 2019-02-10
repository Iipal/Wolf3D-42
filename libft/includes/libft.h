/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:04:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/11 01:56:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "lft_str.h"
# include "lft_lst.h"
# include "lft_mem.h"
# include "lft_put.h"
# include "lft_ctype.h"

# define BUFF_SIZE 2048

int		ft_gnl(const int fd, char **line);
size_t	ft_rand(size_t limits);

#endif
