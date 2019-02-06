/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:07:51 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 14:44:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"

string	ft_strsub(char const *s, unsigned int start, size_t len)
{
	string			src;
	string			out;
	unsigned int	i;
	unsigned int	j;

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
	i = start - 1;
	j = -1;
	while (++j < len)
	{
		++i;
		out[j] = src[i];
	}
	return (out);
}
