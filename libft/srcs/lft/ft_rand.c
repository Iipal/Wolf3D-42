/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 01:54:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/12 12:46:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <fcntl.h>

size_t		ft_rand(size_t limit)
{
	size_t	ponies;
	int		fd;

	fd = open("/dev/urandom", O_RDONLY);
	read(fd, &ponies, sizeof(size_t));
	close(fd);
	return (ponies % limit);
}
