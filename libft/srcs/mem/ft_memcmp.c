/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:13:55 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/26 19:28:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_mem.h"
#include "../../includes/lft_str.h"

int		ft_memcmp(const pvoid s1, const pvoid s2, size_t n)
{
	ustring	str1;
	ustring	str2;

	str2 = (ustring)s2;
	str1 = (ustring)s1;
	if (str1 == str2 || n == 0)
		return (0);
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (n)
		{
			str1++;
			str2++;
		}
	}
	return (0);
}
