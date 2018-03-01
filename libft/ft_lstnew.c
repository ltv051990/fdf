/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 23:10:30 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/07 23:10:31 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list *tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		tmp->next = NULL;
	}
	else if (content != NULL)
	{
		if ((tmp->content = ft_memalloc(content_size)) == NULL)
		{
			free(tmp);
			tmp = NULL;
			return (NULL);
		}
		tmp->content = ft_memmove(tmp->content, content, content_size);
		tmp->content_size = content_size;
		tmp->next = NULL;
	}
	return (tmp);
}
