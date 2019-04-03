/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:45:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:37:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

string	ft_strncpy(string dest, cstring str, size_t len)
{
	string	temp;

	temp = dest;
	while (len--)
		if (*str == '\0')
			*temp++ = 0;
		else
			*temp++ = *str++;
	return (dest);
}
