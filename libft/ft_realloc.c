/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:26:21 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/10 11:26:23 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void *membuf;

	if ((void*)ptr == NULL)
	{
		if (!(ptr = ft_memalloc(size)))
			return (NULL);
		return (ptr);
	}
	if (!(membuf = ft_memalloc(size)))
		return (NULL);
	ft_memcpy(membuf, ptr, size);
	ft_bzero(ptr, ft_strlen(ptr));
	ft_memdel(&ptr);
	return (membuf);
}
