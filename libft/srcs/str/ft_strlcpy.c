/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:20:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:34:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
