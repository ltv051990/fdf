/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:27:53 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/10/26 17:27:57 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		in;
	char		*dest;

	in = ft_strlen(s1);
	dest = (char*)malloc(sizeof(*dest) * (in + 1));
	if (dest == 0)
		return (0);
	in = 0;
	while (s1[in] != '\0')
	{
		dest[in] = s1[in];
		in++;
	}
	dest[in] = '\0';
	return (dest);
}
