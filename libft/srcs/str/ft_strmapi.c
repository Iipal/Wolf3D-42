/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:53:34 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/26 19:32:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"

string	ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	string			src;
	string			out;
	unsigned int	len;
	unsigned int	i;

	i = -1;
	if (!s)
		return (NULL);
	src = (string)s;
	len = ft_strlen(s);
	if ((out = ft_strnew(len)) == NULL)
		return (NULL);
	while (s[++i])
		out[i] = f(i, src[i]);
	return (out);
}
