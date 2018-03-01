/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_cw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:00:50 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/31 16:00:52 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_numb_words(char *s, char c)
{
	size_t	index;
	int		words;
	int		tmp;

	index = 0;
	words = 0;
	tmp = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c)
		{
			if (s[index] != c && tmp == 0)
				words++;
			tmp = 1;
		}
		if (s[index] == c)
			tmp = 0;
		index++;
	}
	return (words);
}

static size_t	ft_start(char *s, char c)
{
	size_t len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static void		ft_delete(char ***dest, size_t index)
{
	size_t	n;

	n = 0;
	while (n <= index)
	{
		free(&(*dest)[n]);
		(*dest)[n] = NULL;
		n++;
	}
	free(*dest);
	(*dest) = NULL;
}

int				ft_split_cw(char const *s, char c, char ***dest)
{
	size_t	i;
	size_t	words;
	int		res;

	if (s == NULL)
		return (0);
	i = 0;
	words = ft_numb_words((char *)s, c);
	res = (int)words;
	(*dest) = (char **)malloc(sizeof(*dest) * (words + 1));
	if (!(*dest))
		return (0);
	while (words > 0)
	{
		while (*s && *s == c)
			s++;
		(*dest)[i] = ft_strsub((const char *)s, 0, ft_start((char *)s, c));
		if (!(*dest)[i])
			ft_delete(dest, i);
		s = s + ft_start((char *)s, c);
		i++;
		words--;
	}
	(*dest)[i] = NULL;
	return (res);
}
