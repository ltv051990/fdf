/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:56:27 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/04 15:56:28 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_search(uint64_t nb)
{
	size_t	count;

	count = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static	char	*ft_trans(char *res, uint64_t nb, size_t count)
{
	while (count--)
	{
		*(res + count) = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (res);
}

char			*ft_itoa_long(uint64_t n)
{
	size_t	count;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	count = ft_search(n);
	res = ft_strnew(count);
	if (res == NULL)
		return (NULL);
	else
		return (ft_trans(res, n, count));
}
