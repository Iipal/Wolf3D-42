/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:11:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:22:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t	ft_atol(string str)
{
	int64_t	num;
	int8_t	sign;

	sign = 0;
	num = 0;
	while (ft_isblank(*str))
		++str;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (ft_isdigit(*str))
		num = num * 10 + *(str++) - 48;
	return (num * sign);
}
