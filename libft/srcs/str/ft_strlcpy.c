/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:20:57 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 10:01:24 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"
#include "../../includes/lft_mem.h"

size_t	ft_strlcpy(string dest, cstring str, size_t dstsize)
{
	size_t	strsize;

	if (str == NULL)
		return (0);
	strsize = ft_strlen(str);
	if (strsize < dstsize)
		ft_memcpy(dest, (pvoid)str, strsize + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dest, (pvoid)str, dstsize - 1);
		dest[dstsize - 1] = '\0';
	}
	return (strsize);
}
