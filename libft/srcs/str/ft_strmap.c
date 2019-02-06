/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:41:28 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/26 19:31:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"

string	ft_strmap(char const *s, char (*f)(char))
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
		out[i] = f(src[i]);
	return (out);
}
