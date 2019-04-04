/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:07:51 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:43:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

string	ft_strsub(char const *s, uint32_t start, size_t len)
{
	string		src;
	string		out;
	uint32_t	i;
	uint32_t	j;

	out = NULL;
	if (s == NULL)
		return (NULL);
	if ((out = ft_strnew(len ? len : 1)) == NULL)
		return (NULL);
	if (len == 0)
	{
		out[0] = '\0';
		return (out);
	}
	src = (string)s;
	i = start;
	j = 0;
	while (j < len)
		out[j++] = src[i++];
	return (out);
}
