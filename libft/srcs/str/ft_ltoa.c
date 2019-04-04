/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 10:33:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:29:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int64_t	ft_slen(bool *sign, int64_t n)
{
	int64_t	out;

	out = 1;
	if (n < 0)
		*sign = true;
	while (n /= 10)
		out++;
	return (out);
}

string			ft_ltoa(int64_t n)
{
	int64_t	len;
	string	out;
	bool	sign;

	if (!n)
	{
		out = ft_strnew(1);
		out[0] = '0';
		return (out);
	}
	sign = false;
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
