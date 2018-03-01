/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 21:04:04 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/10/28 21:04:09 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t index;

	index = ft_strlen(s1);
	while (n-- && *s2 != '\0')
	{
		s1[index] = *s2;
		index++;
		s2++;
	}
	s1[index] = '\0';
	return (s1);
}
