/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_map_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:18:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/09 20:04:15 by tmaluh           ###   ########.fr       */
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
			NOTIS_F(!(map_line[x] < 0 || map_line[x] > MAX_TEXTURES));
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
	IS_F(!(map->size.y = ft_atoi(info_line)) || map->size.y < 0);
	while (info_line[i] && ft_isdigit(info_line[i]))
		++i;
	NOTIS_F(i);
	IS_F(!(map->size.x = ft_atoi(info_line + ++i)) || map->size.x < 0);
	while (info_line[i] && ft_isdigit(info_line[i]))
		++i;
	IS_F(info_line[i]);
	NOTIS_F(map->tab = (int8_t**)malloc(sizeof(int8_t*) * map->size.y));
	NOTIS_F(map->colors = (itab)malloc(sizeof(iarr) * map->size.y));
	i = -1;
	while (++i < map->size.y)
	{
		NOTIS_F(map->tab[i] = (int8_t*)malloc(sizeof(int8_t) * map->size.x));
		NOTIS_F(map->colors[i] = (iarr)malloc(sizeof(int) * map->size.x));
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
				IS(!env->map->tab[y][i], (void)i, true);
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
	string	gnl_temp;
	int		gnl_ret;
	int		fd;
	int		i;

	i = -1;
	gnl_temp = NULL;
	IS_F(!(fd = open(map_name, O_RDONLY)) || fd < 0);
	IS_F(ft_gnl(fd, &gnl_temp) < 0);
	NOTIS_F(add_valid_info(gnl_temp, env->map));
	while ((gnl_ret = ft_gnl(fd, &gnl_temp)) && ++i < env->map->size.y)
	{
		ISM(E_IMAP, add_valid_inline_numbers(gnl_temp) != env->map->size.x,
			ft_strdel(&gnl_temp), false);
		NOTIS(E_IMAP, add_save_map(gnl_temp, MAP[i], MAPC[i],
			env->map->size.x), ft_strdel(&gnl_temp), false);
		NOTIS(E_ENDMAP, add_endofmap(env, i, (point){MAPY, env->map->size.x},
			false), ft_strdel(&gnl_temp), false);
		ft_strdel(&gnl_temp);
	}
	ISM(E_IMAP, gnl_ret || gnl_temp, exit(EXIT_FAILURE), false);
	IS_F(++i != env->map->size.y);
	NOTIS(E_NOFLOOR, add_endofmap(env, 0, (point){env->map->size.y,
		env->map->size.x}, true), exit(EXIT_FAILURE), 0);
	return (true);
}
