/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:19:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:42:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

string	ft_strstr(cstring str, cstring to_find)
{
	string cp;
	string s1;
	string s2;

	cp = (string)str;
	if (!*to_find)
		return ((string)str);
	while (*cp)
	{
		s1 = cp;
		s2 = (string)to_find;
		while (*s1 && *s2 && !(*s1 - *s2))
		{
			s1++;
			s2++;
		}
		if (!*s2)
			return (cp);
		cp++;
	}
	return (0);
}
