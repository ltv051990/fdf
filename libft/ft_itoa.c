/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 22:20:53 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/04 22:20:54 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_search(unsigned long long nb, int negative)
{
	size_t	count;

	count = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	if (negative == -1)
		count = count + 1;
	return (count);
}

static	char	*ft_trans(char *res, unsigned long long nb,\
							int negative, size_t count)
{
	while (count--)
	{
		*(res + count) = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (negative == -1)
		res[0] = '-';
	return (res);
}

char			*ft_itoa(long long int n)
{
	int		negative;
	size_t	count;
	char	*res;

	negative = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		negative = -1;
		n = n * (-1);
	}
	count = ft_search(n, negative);
	res = ft_strnew(count);
	if (res == NULL)
		return (NULL);
	else
		return (ft_trans(res, n, negative, count));
}
