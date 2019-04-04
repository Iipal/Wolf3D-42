/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:46:01 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 12:53:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool		isvalid(uint8_t c, uint8_t base)
{
	char	*valid_lower;
	char	*valid_upper;
	bool	is;

	is = false;
	valid_lower = ft_strdup("0123456789abcdef");
	valid_upper = ft_strdup("0123456789ABCDEF");
	while (base--)
		if (valid_lower[base] == c || valid_upper[base] == c)
		{
			is = true;
			break ;
		}
	ft_strdel(&valid_lower);
	ft_strdel(&valid_upper);
	return (is);
}

static int16_t	value_of(uint8_t c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else if (ft_islower(c))
		return (c - 'a' + 10);
	else if (ft_isupper(c))
		return (c - 'A' + 10);
	return (0);
}

int32_t			ft_atoi_base(cstring str, int8_t base)
{
	int32_t	num;
	int8_t	sign;

	num = 0;
	while (ft_isblank(*str))
		++str;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (isvalid(*str, base))
		num = num * base + value_of(*str++);
	return (num * sign);
}
