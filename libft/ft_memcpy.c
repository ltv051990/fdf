/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:18:40 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/10/27 21:18:45 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;

	if (dst == src)
		return (dst);
	dest = (unsigned char *)dst;
	while (n--)
	{
		*dest = *(unsigned char *)src;
		dest++;
		src++;
	}
	return (dst);
}
