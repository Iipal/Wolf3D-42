/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:43:23 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/30 17:10:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"

size_t	ft_strlcat(string dest,
					cstring src,
					size_t dstsize)
{
	string	dst;
	cstring	sc;
	size_t	n;
	size_t	dlen;

	dst = dest;
	sc = src;
	n = dstsize;
	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - dest;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(sc));
	while (*sc != '\0')
	{
		if (n != 1)
		{
			*dst++ = *sc;
			n--;
		}
		sc++;
	}
	*dst = '\0';
	return (dlen + (sc - src));
}
