/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:33:11 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/26 19:28:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_mem.h"

pvoid	ft_memalloc(size_t size)
{
	pvoid	out;

	out = NULL;
	if (size)
	{
		if ((out = malloc(size)) == NULL)
			return (NULL);
		ft_memset(out, 0, size);
	}
	return (out);
}
