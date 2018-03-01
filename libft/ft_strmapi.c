/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 23:14:14 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/05 23:14:14 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fs;
	size_t			count;
	unsigned int	index;

	index = 0;
	if (s != NULL && f != NULL)
	{
		count = ft_strlen((char *)s);
		fs = ft_strnew(count);
		if (fs != NULL)
		{
			while (s[index] != '\0')
			{
				*(fs + index) = f(index, s[index]);
				index++;
			}
			return (fs);
		}
	}
	return (NULL);
}
