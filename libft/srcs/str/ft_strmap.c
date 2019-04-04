/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:41:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:36:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

string	ft_strmap(char const *s, char (*f)(char))
{
	string		src;
	string		out;
	uint32_t	len;
	uint32_t	i;

	i = 0;
	if (!s)
		return (NULL);
	src = (string)s;
	len = ft_strlen(s);
	if ((out = ft_strnew(len)) == NULL)
		return (NULL);
	while (s[i])
	{
		out[i] = f(src[i]);
		++i;
	}
	return (out);
}
