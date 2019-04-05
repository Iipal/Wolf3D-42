/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlwr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:08:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/05 13:42:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

string	ft_strlwr(string str)
{
	string	s;

	s = str;
	while (*s)
	{
		*s = ft_tolower((uint8_t)*s);
		++s;
	}
	return str;
}
