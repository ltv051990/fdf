/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:22:41 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/03 15:03:53 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dst1;

	dst1 = (unsigned char*)dst;
	if (dst < src)
		while (len--)
			*(unsigned char*)dst++ = *(unsigned char*)src++;
	if (dst > src)
		while (len--)
			*((unsigned char*)dst + len) = *((unsigned char*)src + len);
	return (dst1);
}
