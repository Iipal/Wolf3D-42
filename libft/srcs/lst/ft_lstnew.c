/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 17:56:10 by tmaluh            #+#    #+#             */
/*   Updated: 2018/10/27 18:14:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_lst.h"
#include "../../includes/lft_mem.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*out;

	if ((out = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		out->content = NULL;
		out->content_size = 0;
	}
	else
	{
		if ((out->content = malloc(content_size)) == NULL)
			return (NULL);
		ft_memmove(out->content, content, content_size);
		out->content_size = content_size;
	}
	out->next = NULL;
	return (out);
}
