/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:52:22 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/04 11:52:23 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	size_t size;

	if (s != NULL)
	{
		size = ft_strlen(s);
		while (size--)
			ft_putchar(*s++);
		ft_putchar('\n');
	}
}
