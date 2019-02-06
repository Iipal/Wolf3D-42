/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:04:22 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 14:52:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_mem.h"
#include "../../includes/lft_str.h"

pvoid	ft_memchr(const pvoid s, int c, size_t n)
{
	ustring			out;
	unsigned char	ch;
	int				i;

	i = 0;
	ch = (unsigned char)c;
	out = (ustring)s;
	while (n--)
	{
		if (out[i] == ch)
			return (out + i);
		i++;
	}
	return (NULL);
}
