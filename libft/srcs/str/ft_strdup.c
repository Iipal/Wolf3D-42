/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:03:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:31:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

string	ft_strdup(cstring src)
{
	string	out;
	size_t	i;

	i = 0;
	if ((out = (string)malloc(sizeof(char) * (ft_strlen(src) + 1))) == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		out[i] = src[i];
		++i;
	}
	out[i] = '\0';
	return (out);
}
