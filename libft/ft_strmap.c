/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 22:12:15 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/05 22:12:16 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fs;
	size_t	count;

	if (s != NULL && f != NULL)
	{
		count = ft_strlen(s);
		fs = ft_strnew(count);
		if (fs != NULL)
		{
			while (count--)
				*(fs + count) = f(s[count]);
			return (fs);
		}
	}
	return (NULL);
}
