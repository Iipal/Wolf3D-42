/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlwr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:08:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/05 12:39:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strlwr(string str)
{
	int32_t	i;
	bool	is_alpha;

	i = -1;
	is_alpha = false;
	if (!str)
		return false;
	while (str[++i])
	{
		if (!is_alpha && ft_isalpha(str[i]))
			is_alpha = true;
		str[i] = ft_tolower(str[i]);
	}
	return (is_alpha);
}
