/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_one_of.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 08:33:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/20 08:56:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

bool	ft_is_one_of(long cmp, ...)
{
	va_list	ap;

	va_start(ap, cmp);
	while (true)
		if (cmp == va_arg(ap, long))
		{
			va_end(ap);
			return (true);
		}
	va_end(ap);
	return (false);
}
