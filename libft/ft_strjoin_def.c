/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_def.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:32:01 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/10 12:32:02 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_def(char *s1, char *s2)
{
	char *dest;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (dest == NULL)
		return (NULL);
	ft_strcat(dest, s1);
	ft_strcat(dest, s2);
	ft_strclr(s1);
	ft_strclr(s2);
	ft_memdel((void **)&s1);
	ft_memdel((void **)&s2);
	return (dest);
}
