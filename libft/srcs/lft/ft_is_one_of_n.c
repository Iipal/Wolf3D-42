/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_one_of_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 08:33:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:09:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_one_of_n(int64_t cmp, int64_t n, ...)
{
	va_list	ap;

	va_start(ap, n);
	while (n--)
		if (cmp == va_arg(ap, int64_t))
		{
			va_end(ap);
			return (true);
		}
	va_end(ap);
	return (false);
}
