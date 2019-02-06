/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:39:34 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/27 13:39:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_put.h"

void	ft_putstr_fd(char const *s, int fd)
{
	unsigned int	i;

	i = -1;
	if (s == NULL)
		return ;
	while (s[++i])
		ft_putchar_fd(s[i], fd);
}
