/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 11:06:20 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/10/29 11:06:21 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*find;
	size_t			count;
	char			*last;

	count = ft_strlen((char*)s) + 1;
	last = (char*)s;
	find = &last[ft_strlen((char*)s)];
	while (count >= 1)
	{
		if (*find == (char)c)
			return (find);
		find--;
		count--;
	}
	return (NULL);
}
