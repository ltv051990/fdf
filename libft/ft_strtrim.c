/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:43:57 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/06 19:43:58 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dest;
	size_t	i;
	size_t	c;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		if (i == ft_strlen(s))
		{
			dest = ft_strnew(0);
			if (dest != NULL)
				return (dest);
		}
		c = ft_strlen(s) - 1;
		while (s[c] == ' ' || s[c] == '\t' || s[c] == '\n')
			c--;
		dest = ft_strsub(s, i, (c - i) + 1);
		if (dest == NULL)
			return (NULL);
		return (dest);
	}
	return (NULL);
}
