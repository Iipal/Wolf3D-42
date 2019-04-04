/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:43:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:16:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

pvoid	ft_memmove(pvoid dest, void const *src, size_t len)
{
	size_t	i;
	ustring	dst;
	ustring	sc;

	dst = (ustring)dest;
	sc = (ustring)src;
	i = -1;
	if (sc < dst)
		while ((int64_t)(--len) >= 0)
			dst[len] = sc[len];
	else
		while (++i < len)
			dst[i] = sc[i];
	return (dest);
}
