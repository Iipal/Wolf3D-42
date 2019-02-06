/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:41:32 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 14:14:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"
#include "../../includes/lft_mem.h"

string	ft_strnstr(cstring str, cstring to_find, size_t len)
{
	size_t		n;

	if (*to_find == '\0')
		return ((string)str);
	n = ft_strlen(to_find);
	while (*str && len-- >= n)
	{
		if (*str && *to_find &&
			!ft_memcmp((pvoid)str, (pvoid)to_find, n))
			return ((string)str);
		str++;
	}
	return (NULL);
}
