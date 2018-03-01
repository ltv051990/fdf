/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:07:53 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/10/29 14:07:54 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && ft_strlen(little) <= len)
	{
		if (!(ft_strncmp(big, little, ft_strlen(little))))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
