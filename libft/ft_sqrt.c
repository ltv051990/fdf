/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:42:02 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/10 20:42:04 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int in;
	int res;

	in = 0;
	res = 0;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (0);
	else if (nb == 1)
		return (1);
	while (res <= nb)
	{
		res = in * in;
		if (res == nb)
			return (in);
		in++;
	}
	return (0);
}
