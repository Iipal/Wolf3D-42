/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:06:41 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 14:39:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"
#include "../../includes/lft_mem.h"

string	ft_strnew(size_t size)
{
	string	out;

	out = NULL;
	if ((out = (string)ft_memalloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	ft_memset(out, '\0', size + 1);
	return (out);
}
