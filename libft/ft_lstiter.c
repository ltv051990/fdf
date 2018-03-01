/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:23:05 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/09 18:23:06 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *beg;

	if (lst != NULL && f != NULL)
	{
		beg = lst;
		while (beg)
		{
			f(beg);
			beg = beg->next;
		}
	}
}
