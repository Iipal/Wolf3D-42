/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 12:31:02 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/08 21:06:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int32_t	catline_recursive(int32_t fd, string *data,
								string *line, ssize_t nbytes)
{
	int32_t	to_nl;
	string	temp_nl;

	to_nl = -1;
	while (data[fd][++to_nl] != '\n' &&
			data[fd][to_nl] != '\0')
		;
	if (data[fd][to_nl] == '\n')
	{
		*line = ft_strndup(data[fd], (size_t)to_nl);
		temp_nl = ft_strdup(data[fd] + ++to_nl);
		free(data[fd]);
		data[fd] = temp_nl;
		if (data[fd][0] == '\0')
			ft_strdel(&data[fd]);
	}
	else if (data[fd][to_nl] == '\0')
	{
		if (nbytes == BUFF_SIZE)
			return (ft_gnl(fd, line));
		*line = ft_strdup(data[fd]);
		ft_strdel(&data[fd]);
	}
	return (1);
}

int8_t			ft_gnl(const int32_t fd, string *line)
{
	static string	data[255];
	string			temp;
	char			buff[BUFF_SIZE + 1];
	ssize_t			nbytes;

	if (fd < 0 || !line)
		return (-1);
	while ((nbytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nbytes] = '\0';
		if (!data[fd])
			data[fd] = ft_strnew(0);
		temp = ft_strjoin(data[fd], buff);
		free(data[fd]);
		data[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (nbytes < 0)
		return (-1);
	if (nbytes == 0 &&
		(!data[fd] || data[fd][0] == '\0'))
		return (0);
	return (catline_recursive(fd, data, line, nbytes));
}
