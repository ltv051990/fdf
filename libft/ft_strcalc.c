/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcalc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:46:01 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/11/10 18:46:02 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_searcherror(char **tmp)
{
	if (tmp[1][0] == '/' && ft_atoi(tmp[2]) == 0)
		return (0);
	else if (tmp[1][0] == '%' && ft_atoi(tmp[2]) == 0)
		return (0);
	else
		return (1);
}

static int	ft_calc(char **tmp)
{
	int		res;

	res = 0;
	if (tmp[1][0] == '+')
		res = ft_atoi(tmp[0]) + ft_atoi(tmp[2]);
	else if (tmp[1][0] == '-')
		res = ft_atoi(tmp[0]) - ft_atoi(tmp[2]);
	else if (tmp[1][0] == '*')
		res = ft_atoi(tmp[0]) * ft_atoi(tmp[2]);
	else if (tmp[1][0] == '/')
		res = ft_atoi(tmp[0]) / ft_atoi(tmp[2]);
	else if (tmp[1][0] == '%')
		res = ft_atoi(tmp[0]) % ft_atoi(tmp[2]);
	else if (tmp[1][0] == 'k')
		res = ft_sqrt(ft_atoi(tmp[0]));
	else if (tmp[1][0] == 's')
		res = ft_power(ft_atoi(tmp[0]), ft_atoi(tmp[2]));
	return (res);
}

char		*ft_strcalc(char *src)
{
	int		res;
	char	**tmp;
	char	*eq;

	res = 0;
	if (src == NULL)
		return (NULL);
	tmp = ft_strsplit(src, ' ');
	if (tmp == NULL || tmp[0] == NULL || tmp[3] != NULL)
		return (NULL);
	if (!(ft_searcherror(tmp)))
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	res = ft_calc(tmp);
	eq = ft_itoa(res);
	free(tmp);
	tmp = NULL;
	return (eq);
}
