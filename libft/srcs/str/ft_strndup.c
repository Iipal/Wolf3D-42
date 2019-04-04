/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:01:32 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:38:21 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

string	ft_strndup(cstring src, size_t n)
{
	string	out;
	size_t	i;

	i = 0;
	if ((out = ft_strnew(n)) == NULL)
		return (NULL);
	while (src[i] != '\0' && i < n)
	{
		out[i] = src[i];
		++i;
	}
	return (out);
}
