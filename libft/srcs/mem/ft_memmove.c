/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:43:44 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/26 19:29:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_mem.h"
#include "../../includes/lft_str.h"

pvoid	ft_memmove(pvoid dest, void const *src, size_t len)
{
	size_t	i;
	ustring	dst;
	ustring	sc;

	dst = (ustring)dest;
	sc = (ustring)src;
	i = -1;
	if (sc < dst)
		while ((int)(--len) >= 0)
			dst[len] = sc[len];
	else
		while (++i < len)
			dst[i] = sc[i];
	return (dest);
}
