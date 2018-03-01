/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:05:29 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/12 11:05:30 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int32_t	ft_is_basenb(char str)
{
	if ((str >= '0' && str <= '9') || (str >= 'A' && str <= 'F') ||\
		(str >= 'a' && str <= 'f'))
		return (1);
	return (0);
}

static int32_t	ft_base(char str, int base)
{
	if (str >= '0' && str <= '9')
		return (str - 48);
	if (str >= 'A' && str <= 'F')
		return (--base - ('F' - str));
	return (--base - ('f' - str));
}

static	int64_t	ft_base_calc(char *str, int base, int count)
{
	int			power;
	long int	tmp;
	int			res;

	power = 1;
	tmp = 0;
	res = 0;
	while (count--)
	{
		--str;
		res = (ft_base(*str, base) * power);
		power = power * base;
		tmp = tmp + res;
	}
	return (tmp);
}

int64_t			ft_atoi_base(char *str, int base)
{
	int			negative;
	int			count;

	negative = 1;
	count = 0;
	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\t' ||\
			*str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_is_basenb(*str))
	{
		count++;
		str++;
	}
	return (ft_base_calc((char *)str, base, count) * negative);
}
