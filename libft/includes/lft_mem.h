/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_mem.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:15:42 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/15 09:15:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_MEM_H
# define LFT_MEM_H

# include "lft_str.h"

# define _PVOID	typedef	void*	pvoid

_PVOID;

void	ft_bzero(pvoid s, size_t n);
void	ft_memdel(pvoid *ap);

pvoid	ft_memset(pvoid b, int c, size_t len);
pvoid	ft_memcpy(pvoid dest, const pvoid src, size_t n);
pvoid	ft_memccpy(pvoid dest, const pvoid src,
						int c, size_t n);
pvoid	ft_memmove(pvoid dest, void const *src, size_t len);
pvoid	ft_memchr(const pvoid s, int c, size_t n);
pvoid	ft_memalloc(size_t size);

int		ft_memcmp(const pvoid s1, const pvoid s2, size_t n);

#endif
