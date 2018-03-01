/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:18:14 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/10/28 22:18:16 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t index;

	if (dst == NULL && size == 0)
		return (ft_strlen(src));
	index = ft_strlen(dst);
	if (size > index)
	{
		while (size - 1 > index && *src != '\0')
		{
			dst[index] = *src;
			index++;
			src++;
		}
		dst[index] = '\0';
		return (ft_strlen(src) + index);
	}
	return (ft_strlen(src) + size);
}
