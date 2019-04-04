/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:07:43 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:39:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

string	ft_strrchr(cstring s, uint8_t c)
{
	int32_t	len;

	len = ft_strlen((string)s);
	while (len > 0 && s[len] != c)
		len--;
	if (s[len] == c)
		return ((string)&s[len]);
	return (NULL);
}
