/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:35:16 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/04 15:35:17 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	size_t size;

	if (fd > 0 && s != NULL)
	{
		size = ft_strlen(s);
		while (size--)
			ft_putchar_fd(*s++, fd);
	}
}
