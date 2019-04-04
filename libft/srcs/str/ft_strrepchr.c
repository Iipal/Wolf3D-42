/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:20:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:41:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strrepchr(cstring str, char find_sumbol, char replace_sumbol)
{
	string ptr;

	if (!str)
		return (false);
	while ((ptr = ft_strchr(str, find_sumbol)))
		*ptr = replace_sumbol;
	return (true);
}
