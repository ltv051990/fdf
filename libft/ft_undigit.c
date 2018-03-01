/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:23:15 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/04 16:23:15 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static		void	ft_udnbstr_with_prezition(char **a, long long b,\
											t_struct *flags)
{
	char			*src;

	flags->count_nb = ft_search_un((b >= 0 ? b : b * -1));
	src = ft_itoa_long(b);
	if (flags->presizion > flags->count_nb)
	{
		*a = ft_strnew(flags->presizion + 1);
		ft_memset(*a, '0', flags->presizion - flags->count_nb);
		*a = ft_strcat(*a, src);
		free(src);
	}
	else
		*a = src;
	if (b == 0 && flags->presizion == 0)
	{
		ft_strdel(&src);
		*a = ft_strnew(0);
	}
}

static		void	ft_udnbstr_with_minsize2(char **a, t_struct *flags,\
											int delta_size)
{
	char			*g;

	g = ft_strnew(flags->min_size);
	if (delta_size > 0 && flags->minus == '-')
	{
		g = ft_strcpy(g, *a);
		ft_memset(g + ft_strlen(*a), ' ', delta_size);
	}
	else if (delta_size > 0 && flags->minus != '-' && flags->zero == '\0')
	{
		ft_memset(g, ' ', delta_size);
		g = ft_strcat(g, *a);
	}
	else if (flags->minus != '-' && flags->zero == '0')
	{
		ft_memset(g, '0', delta_size);
		g = ft_strcat(g, *a);
	}
	ft_strdel(a);
	*a = g;
}

static		void	ft_udnbstr_with_minsize(char **a, t_struct *flags)
{
	char			*g;
	int				delta_size;

	if (flags->presizion >= 0 && flags->min_size > (int)ft_strlen(*a))
	{
		g = ft_strnew(flags->min_size);
		if (flags->minus == '-')
		{
			g = ft_strcpy(g, *a);
			ft_memset(g + ft_strlen(*a), ' ', \
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
	if (flags->presizion == -1 && delta_size > 0)
		ft_udnbstr_with_minsize2(a, flags, delta_size);
}

void				ft_undigit(va_list ap, t_struct *flags)
{
	char			*a;
	uint64_t		b;

	ft_take_ud(&b, ap, flags);
	ft_udnbstr_with_prezition(&a, b, flags);
	ft_udnbstr_with_minsize(&a, flags);
	write(1, a, ft_strlen(a));
	flags->write_count += ft_strlen(a);
	free(a);
}

void				ft_un_big_digit(va_list ap, t_struct *flags)
{
	char			*a;
	uint64_t		b;

	b = va_arg(ap, uint64_t);
	ft_udnbstr_with_prezition(&a, b, flags);
	ft_udnbstr_with_minsize(&a, flags);
	write(1, a, ft_strlen(a));
	flags->write_count += ft_strlen(a);
	free(a);
}
