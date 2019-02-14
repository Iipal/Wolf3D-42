/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:20:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/14 11:21:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"

int	ft_strrepchr(cstring str, char find_sumbol, char replace_sumbol)
{
	string ptr;

	if (!str)
		return (0);
	while ((ptr = ft_strchr(str, find_sumbol)))
		*ptr = replace_sumbol;
	return (1);
}
