/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 12:31:02 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/30 00:35:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/lft_str.h"

static int	catline_recursive(int fd, string *data, string *line, int nbytes)
{
	int		to_nl;
	string	temp_nl;

	to_nl = -1;
	while (data[fd][++to_nl] != '\n' &&
			data[fd][to_nl] != '\0')
		;
	if (data[fd][to_nl] == '\n')
	{
		*line = ft_strndup(data[fd], to_nl);
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

int			ft_gnl(const int fd, string *line)
{
	static string	data[255];
	string			temp;
	char			buff[BUFF_SIZE + 1];
	int				nbytes;

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
