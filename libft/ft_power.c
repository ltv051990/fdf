/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:45:45 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/10 20:55:19 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int nb, int power)
{
	int res;

	res = nb;
	if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	else if (power > 1)
	{
		while (power-- > 1)
			res = nb * res;
		return (res);
	}
	return (-1);
}
