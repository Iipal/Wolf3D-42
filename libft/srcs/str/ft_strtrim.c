/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:26:18 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/26 20:03:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"

string	ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (s[start] == ' ' ||
			s[start] == '\n' ||
			s[start] == '\t')
		start++;
	if (s[start] == '\0')
		return (ft_strdup(s + start));
	len = ft_strlen(s) - 1;
	while ((s[len] == ' ' ||
			s[len] == '\t' ||
			s[len] == '\n') && len > 0)
		len--;
	return (ft_strsub(s, start, len - start + 1));
}
