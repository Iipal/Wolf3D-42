/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_map_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:18:56 by tmaluh            #+#    #+#             */
/*   Updated: 2020/03/22 14:48:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static bool		add_save_map(string line, int8_t *map_line,
						iarr colors_line, int map_x)
{
	const int	colors[] = {RGB_WHITE, RGB_RED, RGB_ORANGE, RGB_LIME,
						RGB_AQUA, RGB_PURPLE, RGB_MINT, RGB_DARK_BLUE};
	string		temp_digits;
	int			digits;
	int			x;

	x = -1;
	while (*line && x < map_x)
	{
		if (ft_isdigit(*line))
		{
			map_line[++x] = ft_atoi(line);
			if (0 > map_line[x] || MAX_TEXTURES < map_line[x])
				return (false);
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

static bool		add_valid_info(string info_line, t_map *map)
{
	int		i;

	i = 0;
	IF_F(!(map->size.y = ft_atoi(info_line)) || map->size.y < 0);
	while (info_line[i] && ft_isdigit(info_line[i]))
		++i;
	NO_F(i);
	IF_F(!(map->size.x = ft_atoi(info_line + ++i)) || map->size.x < 0);
	while (info_line[i] && ft_isdigit(info_line[i]))
		++i;
	IF_F(info_line[i]);
	NO_F(map->tab = (int8_t**)malloc(sizeof(int8_t*) * map->size.y));
	NO_F(map->colors = (itab)malloc(sizeof(iarr) * map->size.y));
	i = -1;
	while (++i < map->size.y)
	{
		NO_F(map->tab[i] = (int8_t*)malloc(sizeof(int8_t) * map->size.x));
		NO_F(map->colors[i] = (iarr)malloc(sizeof(int) * map->size.x));
	}
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
				NO_R(env->map->tab[y][i], true);
		return (false);
	}
	else if (!y || y == map_max.y - 1)
	{
		while (i < map_max.x)
			if (env->map->tab[y][i] > 0)
				++i;
			else
				break ;
		return ((i != map_max.x) ? false : true);
	}
	else if (!env->map->tab[y][0]
	|| !env->map->tab[y][map_max.x - 1])
		return (false);
	return (true);
}

bool			wolf_readnsave(string map_name, t_env *env)
{
	const int32_t	fd = open(map_name, O_RDONLY);
	string			gnl_temp;
	int32_t			gnl_ret;
	size_t			i;

	i = ~0UL;
	gnl_temp = NULL;
	IF_F(!fd || 0 > fd);
	IFDO_F(ft_gnl(fd, &gnl_temp) < 0, close(fd));
	NO_F(add_valid_info(gnl_temp, env->map));
	while ((gnl_ret = ft_gnl(fd, &gnl_temp)) && (size_t)env->map->size.y > ++i)
	{
		IFDOMR(E_IMAP, add_valid_inline_numbers(gnl_temp) != env->map->size.x,
			ft_strdel(&gnl_temp), false);
		NODOM_F(E_IMAP, add_save_map(gnl_temp, MAP[i], MAPC[i],
			env->map->size.x), ft_strdel(&gnl_temp));
		NODOM_F(E_ENDMAP, add_endofmap(env, i, (point){MAPY, env->map->size.x},
			false), ft_strdel(&gnl_temp));
		ft_strdel(&gnl_temp);
	}
	close(fd);
	IFM_F(E_IMAP, gnl_ret || gnl_temp);
	IF_F(++i != (size_t)env->map->size.y);
	NOM_F(E_NOFLOOR, add_endofmap(env, 0, (point){env->map->size.y,
		env->map->size.x}, true));
	return (true);
}
