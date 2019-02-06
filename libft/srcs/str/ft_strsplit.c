/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <tmaluh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:58:29 by tmaluh            #+#    #+#             */
/*   Updated: 2018/12/19 20:34:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"

static inline int	ft_ss_words(cstring str, string ch)
{
	int		counter;
	int		is_word;

	counter = 0;
	is_word = 0;
	while (*str)
	{
		if (is_word && *str == *ch)
			is_word = 0;
		if (!is_word && *str != *ch)
		{
			counter++;
			is_word = 1;
		}
		str++;
	}
	return (counter);
}

static inline int	ft_ss_wlen(cstring str, char ch)
{
	int		len;

	len = 0;
	while (*str != ch && *str++ != '\0')
		len++;
	return (len);
}

strtab				ft_strsplit(char const *s, char c)
{
	strtab	out;
	int		w_counter;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	w_counter = ft_ss_words(s, &c);
	if ((out = (string*)malloc(sizeof(string) * w_counter + 1)) == NULL)
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
