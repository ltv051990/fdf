/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 10:15:08 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/10/29 10:15:10 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*find;

	find = (char *)s;
	if (c == 0)
		return (&find[ft_strlen(find)]);
	while (*find != '\0')
	{
		if (*find == (char)c)
			return (find);
		find++;
	}
	return (NULL);
}
