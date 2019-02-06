/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:35:59 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/28 15:03:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"

void	ft_striteri(string s, void (*f)(unsigned int, string))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = -1;
	if (s)
		while (s[++i])
			f(i, &s[i]);
}
