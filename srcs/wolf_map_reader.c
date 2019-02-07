/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_map_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:18:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/07 11:37:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static bool		add_save_map(string line, iarr map_line, int map_x)
{
	string	temp_digits;
	int		digits;
	int		x;

	x = -1;
	while (*line && x < map_x)
	{
		if (ft_isdigit(*line))
		{
			map_line[++x] = ft_atoi(line);
			_NOTIS_F(!(map_line[x] < 0 || map_line[x] > MAX_TEXTURES));
			temp_digits = ft_itoa(map_line[x]);
			digits = ft_strlen(temp_digits);
			ft_strdel(&temp_digits);
			(line[digits] != '\0') ? (line += digits) : (line += --digits);
		}
		*line ? ++line : 0;
	}
	return (true);
}

static int		add_valid_inline_numbers(string line)
{
	string	temp_digits;
	int		out;
	int		digits;

	out = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			temp_digits = ft_itoa(ft_atoi(line));
			digits = ft_strlen(temp_digits);
			ft_strdel(&temp_digits);
			(line[digits] != '\0') ? (line += digits) : (line += --digits);
			++out;
		}
		*line ? ++line : 0;
	}
	return (out);
}

static bool		add_valid_info_line(string info_line, t_map *map)
{
	strtab	info_tab;
	int		i;

	_NOTIS_F(info_tab = ft_strsplit(info_line, ' '));
	_NOTIS_F(map->ysize = ft_atoi(info_tab[0]));
	ft_strdel(&info_tab[0]);
	_NOTIS_F(map->xsize = ft_atoi(info_tab[1]));
	ft_strdel(&info_tab[1]);
	_NOTIS_F(!info_tab[2]);
	free(info_tab);
	_NOTIS_F(map->tab = malloc(sizeof(iarr) * map->ysize));
	i = -1;
	while (++i < map->ysize)
		_NOTIS_F(map->tab[i] = malloc(sizeof(int) * map->xsize));
	ft_strdel(&info_line);
	return (true);
}

static bool		add_valid_endofmap(iarr map_line, int y, int maxy, int line_len)
{
	int	i;

	i = 0;
	if (!y || y == --maxy)
	{
		while (i < line_len)
			if (map_line[i] > 0)
				++i;
			else
				break ;
		return ((i != line_len) ? false : true);
	}
	else if (!map_line[0] || !map_line[--line_len])
		return (false);
	return (true);
}

bool			wolf_readnsave(string map_name, t_env *env)
{
	string	gnl_temp;
	int		gnl_ret;
	int		fd;
	int		i;

	i = -1;
	_NOTIS_F(!(!(fd = open(map_name, O_RDONLY)) || fd < 0));
	_NOTIS_F(!(ft_gnl(fd, &gnl_temp) < 0));
	_NOTIS_F(add_valid_info_line(gnl_temp, env->map));
	while ((gnl_ret = ft_gnl(fd, &gnl_temp)) && ++i < MAPY)
	{
		_NOTIS(E_IMAP, !(add_valid_inline_numbers(gnl_temp) != MAPX),
			ft_strdel(&gnl_temp), false);
		_NOTIS(E_ALLOC, add_save_map(gnl_temp, MAP[i], MAPX),
			ft_strdel(&gnl_temp), false);
		_NOTIS(E_ENDMAP, add_valid_endofmap(MAP[i], i, MAPY, MAPX),
			ft_strdel(&gnl_temp), false);
		ft_strdel(&gnl_temp);
	}
	_NOTIS(E_IMAP, !(gnl_ret || gnl_temp), ft_strdel(&gnl_temp), false);
	_NOTIS_F(!(++i != MAPY));
	return (true);
}
