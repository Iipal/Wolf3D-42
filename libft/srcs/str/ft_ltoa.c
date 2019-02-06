/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 10:33:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/01/16 10:46:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"

static inline long	ft_slen(long *in, long n)
{
	long	out;

	out = 1;
	if (n < 0)
		*in = 1;
	while (n /= 10)
		out++;
	return (out);
}

string				ft_ltoa(long n)
{
	long	len;
	long	sign;
	string	out;

	if (!n)
	{
		out = ft_strnew(1);
		out[0] = '0';
		return (out);
	}
	sign = 0;
	len = ft_slen(&sign, n);
	if ((out = ft_strnew(len + sign)) == NULL)
		return (NULL);
	if (sign)
		out[0] = '-';
	while (len--)
	{
		out[len + sign] = (sign ? -(n % 10) : n % 10) + '0';
		n /= 10;
	}
	return (out);
}
