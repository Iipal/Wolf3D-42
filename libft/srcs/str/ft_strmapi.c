/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:53:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 12:54:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

string	ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		out[i] = f(i, src[i]);
		++i;
	}
	return (out);
}
