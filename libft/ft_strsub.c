/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:11:47 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/06 17:11:48 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	index;

	if (!s)
		return (NULL);
	dest = ft_strnew(len);
	if (!dest)
		return (NULL);
	index = 0;
	while (index < len)
	{
		dest[index] = s[start];
		index++;
		start++;
	}
	dest[index] = '\0';
	return (dest);
}
