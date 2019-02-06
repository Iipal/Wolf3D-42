/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:43:45 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/26 19:28:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_mem.h"
#include "../../includes/lft_str.h"

pvoid	ft_memccpy(pvoid dest,
					const pvoid src,
					int c, size_t n)
{
	unsigned char	ch;
	ustring			dst;
	ustring			sc;
	size_t			i;

	dst = (ustring)dest;
	sc = (ustring)src;
	i = 0;
	ch = c;
	while (i < n)
	{
		dst[i] = sc[i];
		if (sc[i] == ch)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
