/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:04:50 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:15:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

pvoid	ft_memcpy(pvoid dest, const pvoid src, size_t n)
{
	size_t	i;
	string	dst;
	string	sc;

	dst = (string)dest;
	sc = (string)src;
	i = 0;
	while (i < n)
	{
		dst[i] = sc[i];
		++i;
	}
	return (dest);
}
