/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:11:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:23:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_atoi(string str)
{
	int32_t	num;
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
