/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:04:22 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:14:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

pvoid	ft_memchr(const pvoid s, uint8_t c, size_t n)
{
	ustring			out;
	size_t			i;

	i = 0;
	out = (ustring)s;
	while (n--)
	{
		if (out[i] == c)
			return (out + i);
		++i;
	}
	return (NULL);
}
