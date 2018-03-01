/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:09:01 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/10/26 18:09:02 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t nb;

	nb = 0;
	while (nb < len && *src != '\0')
	{
		dest[nb] = *src;
		nb++;
		src++;
	}
	while (nb < len)
	{
		dest[nb] = '\0';
		nb++;
	}
	return (dest);
}
