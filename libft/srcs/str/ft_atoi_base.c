/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:46:01 by tmaluh            #+#    #+#             */
/*   Updated: 2018/11/21 16:46:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"
#include "../../includes/lft_ctype.h"

static int	isvalid(int c, int base)
{
	char	*valid_lower;
	char	*valid_upper;
	int		is;

	is = 0;
	valid_lower = ft_strdup("0123456789abcdef");
	valid_upper = ft_strdup("0123456789ABCDEF");
	while (base--)
		if (valid_lower[base] == c || valid_upper[base] == c)
		{
			is = 1;
			break ;
		}
	ft_strdel(&valid_lower);
	ft_strdel(&valid_upper);
	return (is);
}

static int	value_of(int c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else if (ft_islower(c))
		return (c - 'a' + 10);
	else if (ft_isupper(c))
		return (c - 'A' + 10);
	return (0);
}

int			ft_atoi_base(cstring str, int base)
{
	int	result;
	int	sign;

	result = 0;
	while (ft_isblank(*str))
		++str;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (isvalid(*str, base))
		result = result * base + value_of(*str++);
	return (result * sign);
}
