/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:45:37 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/10/26 12:45:40 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_is_space(char str)
{
	if (str == ' ' || str == '\n' || str == '\t' ||\
	str == '\f' || str == '\r' || str == '\v')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int					negative;
	unsigned long int	res;
	unsigned long int	restemp;

	res = 0;
	negative = 1;
	while (ft_is_space(*str))
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		restemp = (res * 10) + (*str - '0');
		str++;
		if (((negative == -1) && (restemp > 9223372036854775807)) \
		|| (restemp < res && (negative == -1)))
			return (0);
		if (((negative == 1) && (restemp > 9223372036854775806)) \
		|| (restemp < res && (negative == 1)))
			return (-1);
		res = restemp;
	}
	return (res * negative);
}
