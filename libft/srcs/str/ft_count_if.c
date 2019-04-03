/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 10:33:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:24:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_count_if(cstring str, uint8_t ch)
{
	int32_t	counter;
	int32_t	i;

	i = -1;
	counter = 0;
	if (!str || !ch)
		return (counter);
	while (str[++i] != '\0')
		if (str[i] == ch)
			counter++;
	return (counter);
}
