/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:07:43 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 14:55:21 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"

string	ft_strrchr(cstring s, int c)
{
	int	len;

	len = ft_strlen((string)s);
	while (len > 0 && s[len] != c)
		len--;
	if (s[len] == c)
		return ((string)&s[len]);
	return (NULL);
}
