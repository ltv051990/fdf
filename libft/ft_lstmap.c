/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:14:35 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/09 20:14:36 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *beg;
	t_list *begin;
	t_list *new;

	if (lst != NULL && *f != NULL)
	{
		beg = f(lst);
		if ((new = ft_lstnew(beg->content, beg->content_size)) == NULL)
			return (NULL);
		begin = new;
		lst = lst->next;
		while (lst)
		{
			beg = f(lst);
			if (!(new->next = ft_lstnew(beg->content, beg->content_size)))
			{
				ft_lstdel(&begin, ft_bzero);
				return (NULL);
			}
			new = new->next;
			lst = lst->next;
		}
		return (begin);
	}
	return (NULL);
}
