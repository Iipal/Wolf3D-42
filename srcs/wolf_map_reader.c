/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_map_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:18:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/02/18 17:24:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static bool		add_save_map(string line, iarr map_line,
						iarr colors_line, int map_x)
{
	const int	colors[] = {IRGB_WHITE, IRGB_RED, IRGB_ORANGE, IRGB_LIME,
							IRGB_AQUA, IRGB_PURPLE, IRGB_MINT, IRGB_DARK_BLUE};
	string		temp_digits;
	int			digits;
	int			x;

	x = -1;
	while (*line && x < map_x)
	{
		if (ft_isdigit(*line))
		{
			map_line[++x] = ft_atoi(line);
			_NOTIS_F(!(map_line[x] < 0 || map_line[x] > MAX_TEXTURES));
			colors_line[x] = colors[map_line[x] - 1];
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
		if (*line == '-')
			break ;
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

static bool		add_valid_info(string info_line, t_map *map, string map_name)
{
	strtab	info_tab;
	int		i;

	_NOTIS_F(!ft_strcmp(map_name +
		(ft_strlen(map_name) - ft_strlen(WOLF_FILE_EXT)), WOLF_FILE_EXT));
	_NOTIS_F(info_tab = ft_strsplit(info_line, ' '));
	_NOTIS_F(map->ysize = ft_atoi(info_tab[0]));
	_NOTIS_F(map->xsize = ft_atoi(info_tab[1]));
	_NOTIS_F(!info_tab[2]);
	_NOTIS_F(map->tab = (itab)malloc(sizeof(iarr) * map->ysize));
	_NOTIS_F(map->colors = (itab)malloc(sizeof(iarr) * map->ysize));
	i = -1;
	while (++i < map->ysize)
	{
		if (i < 2)
			ft_strdel(&(info_tab[i]));
		_NOTIS_F(map->tab[i] = (iarr)malloc(sizeof(int) * map->xsize));
		_NOTIS_F(map->colors[i] = (iarr)malloc(sizeof(int) * map->xsize));
	}
	_FREE(info_tab, free);
	ft_strdel(&info_line);
	return (true);
}

static bool		add_endofmap(t_env *env, int y,
								point map_max, bool valid_all)
{
	int	i;

	i = 0;
	if (valid_all)
	{
		while (++y < map_max.y - 1 && (i = -1))
			while (++i < map_max.x)
				if (MAP[y][i] == 0)
					return (true);
		return (false);
	}
	else if (!y || y == map_max.y - 1)
	{
		while (i < map_max.x)
			if (MAP[y][i] > 0)
				++i;
			else
				break ;
		return ((i != map_max.x) ? false : true);
	}
	else if (!MAP[y][0] || !MAP[y][map_max.x - 1])
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
	gnl_temp = NULL;
	_NOTIS_F(!(!(fd = open(map_name, O_RDONLY)) || fd < 0));
	_NOTIS_F(!(ft_gnl(fd, &gnl_temp) < 0));
	_NOTIS_F(add_valid_info(gnl_temp, env->map, map_name));
	while ((gnl_ret = ft_gnl(fd, &gnl_temp)) && ++i < MAPY)
	{
		_NOTIS(E_IMAP, !(add_valid_inline_numbers(gnl_temp) != MAPX),
			ft_strdel(&gnl_temp), false);
		_NOTIS(E_IMAP, add_save_map(gnl_temp, MAP[i], MAPC[i], MAPX),
			ft_strdel(&gnl_temp), false);
		_NOTIS(E_ENDMAP, add_endofmap(env, i, (point){MAPY, MAPX}, false),
			ft_strdel(&gnl_temp), false);
		ft_strdel(&gnl_temp);
	}
	_NOTIS(E_IMAP, !(gnl_ret || gnl_temp), exit(EXIT_FAILURE), false);
	_NOTIS_F(!(++i != MAPY));
	_NOTIS(E_NOFLOOR, add_endofmap(env, 0, (point){MAPY, MAPX}, true),
		exit(EXIT_FAILURE), 0);
	return (true);
}
