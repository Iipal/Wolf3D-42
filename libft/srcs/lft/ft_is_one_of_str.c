/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_one_of_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:08:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 23:17:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_one_of_str(cstring cmp, int32_t n, ...)
{
	va_list	ap;
	bool	is_one_of;

	va_start(ap, n);
	is_one_of = false;
	while (n--)
		if (!ft_strcmp(cmp, va_arg(ap, char*)))
			is_one_of = true;
	va_end(ap);
	return (is_one_of);
}
