/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:14:26 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/06 18:14:27 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *dest;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (dest == NULL)
		return (NULL);
	ft_strcat(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}
