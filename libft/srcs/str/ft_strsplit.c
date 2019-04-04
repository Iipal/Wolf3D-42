/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:58:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/04 01:42:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int32_t	ft_ss_words(cstring str, string ch)
{
	int32_t	counter;
	bool	is_word;

	counter = 0;
	is_word = false;
	while (*str)
	{
		if (is_word && *str == *ch)
			is_word = true;
		if (!is_word && *str != *ch)
		{
			counter++;
			is_word = false;
		}
		str++;
	}
	return (counter);
}

static int32_t	ft_ss_wlen(cstring str, char ch)
{
	int32_t	len;

	len = 0;
	while (*str != ch && *str++ != '\0')
		len++;
	return (len);
}

strtab			ft_strsplit(char const *s, char c)
{
	strtab	out;
	int32_t	w_counter;
	int32_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	w_counter = ft_ss_words(s, &c);
	if ((out = (string*)malloc(sizeof(string) * (w_counter + 1))) == NULL)
		return (NULL);
	while (w_counter--)
	{
		while (*s == c && *s != '\0')
			s++;
		out[i] = ft_strsub(s, 0, ft_ss_wlen(s, c));
		if (out[i] == NULL)
			return (NULL);
		s = s + ft_ss_wlen(s, c);
		i++;
	}
	out[i] = NULL;
	return (out);
}
