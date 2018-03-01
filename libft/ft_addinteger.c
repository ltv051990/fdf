/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addinteger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:27:32 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/09 19:27:33 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*** add functions for un_digit(U/u)
*/

size_t			ft_search_un(uint64_t nb)
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

/*
*** add functions for un_digit(U/u)
*/

void			ft_take_ud(uint64_t *b, va_list ap, t_struct *flags)
{
	if (flags->mod_size == 'z' || flags->mod_size == 'j' ||\
		flags->mod_size == 'L' || flags->mod_size == 'l')
		*b = va_arg(ap, uint64_t);
	else if (flags->mod_size == 'h')
		*b = (unsigned short int)va_arg(ap, void*);
	else if (flags->mod_size == 'H')
		*b = (unsigned char)va_arg(ap, void*);
	else
		*b = va_arg(ap, uint32_t);
}

/*
*** add functions for digit(D/d)
*/

size_t			ft_search_dig(long long int nb)
{
	size_t		count;

	count = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

/*
*** add functions for digit(D/d)
*/

static	void	ft_nbstr_with_minsize2(char **a, t_struct *flags,\
											int delta_size)
{
	char		*g;

	g = ft_strnew(flags->min_size);
	if (delta_size > 0 && flags->minus == '-' && (g = ft_strcpy(g, *a)))
		ft_memset(g + ft_strlen(*a), ' ', delta_size);
	else if (delta_size > 0 && flags->minus != '-' && flags->zero == '\0')
	{
		ft_memset(g, ' ', delta_size);
		g = ft_strcat(g, *a);
	}
	else if (flags->minus != '-' && flags->zero == '0')
	{
		if ((**a == ' ' || **a == '+' || **a == '-') && (g[0] = **a))
		{
			ft_memset(g + 1, '0', delta_size);
			g = ft_strcat(g, (*a) + 1);
		}
		else
		{
			ft_memset(g, '0', delta_size);
			g = ft_strcat(g, *a);
		}
	}
	ft_strdel(a);
	*a = g;
}

/*
*** add functions for digit(D/d)
*/

void			ft_nbstr_with_minsize(char **a, t_struct *flags)
{
	char		*g;
	int			delta_size;

	if (flags->presizion >= 0 && flags->min_size > (int)ft_strlen(*a))
	{
		g = ft_strnew(flags->min_size);
		if (flags->minus == '-')
		{
			g = ft_strcpy(g, *a);
			ft_memset(g + ft_strlen(*a), ' ',\
						flags->min_size - (int)ft_strlen(*a));
		}
		else
		{
			ft_memset(g, ' ', flags->min_size - (int)ft_strlen(*a));
			ft_strcat(g, *a);
		}
		ft_strdel(a);
		*a = g;
	}
	delta_size = ft_min_pole_s(flags, (int)ft_strlen(*a));
	if ((flags->presizion == -1 && delta_size > 0))
		ft_nbstr_with_minsize2(a, flags, delta_size);
}
