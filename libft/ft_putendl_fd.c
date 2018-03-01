/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:42:26 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/04 16:42:27 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t size;

	if (fd > 0 && s != NULL)
	{
		size = ft_strlen(s);
		while (size--)
			ft_putchar_fd(*s++, fd);
		ft_putchar_fd('\n', fd);
	}
}
