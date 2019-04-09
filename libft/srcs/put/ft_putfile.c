/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:21:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 12:23:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_putfile(string file)
{
	int32_t	fd;
	string	temp;

	temp = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	while (ft_gnl(fd, &temp) > 0)
	{
		ft_putendl(temp);
		ft_strdel(&temp);
	}
	if (temp)
		ft_strdel(&temp);
	return (true);
}
