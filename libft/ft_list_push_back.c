/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lish_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 23:06:42 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/10 23:06:43 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **alst, t_list *new)
{
	t_list *beg;

	if (!alst)
		return ;
	else if (!(*alst))
		(*alst) = new;
	else
	{
		beg = (*alst);
		while (beg->next)
			beg = beg->next;
		beg->next = new;
	}
}
