/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 19:59:27 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/05 19:59:28 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static		void		ft_octet_with_prezition(char **a, uint64_t b,\
											t_struct *flags)
{
	char				*src;

	src = NULL;
	flags->count_nb = ft_strlen(*a);
	if (flags->presizion > flags->count_nb)
	{
		src = ft_strnew(flags->presizion);
		ft_memset(src, '0', flags->presizion - flags->count_nb);
		src = ft_strcat(src, *a);
		ft_strdel(a);
		*a = src;
	}
	if (flags->sharp == 1 && b != 0 && flags->presizion <= flags->count_nb)
	{
		src = ft_strjoin("0", *a);
		ft_strdel(a);
		*a = src;
	}
	if (b == 0 && flags->presizion == 0 && flags->sharp != 1)
	{
		ft_strdel(&src);
		*a = ft_strnew(0);
	}
}

static		void		ft_hex_octet_minsizep2(char **a, t_struct *flags,\
											int delta_size)
{
	char				*g;

	g = ft_strnew(flags->min_size);
	if (delta_size > 0 && flags->minus == '-')
	{
		g = ft_strcpy(g, *a);
		ft_memset(g + ft_strlen(*a), ' ', delta_size);
	}
	else if (flags->minus != '-' && flags->zero == '\0')
	{
		ft_memset(g, ' ', delta_size);
		g = ft_strcat(g, *a);
	}
	else if (flags->minus != '-' && flags->zero == '0' && flags->sharp == 0)
	{
		ft_memset(g, '0', delta_size);
		g = ft_strcat(g, *a);
	}
	ft_strdel(a);
	*a = g;
}

static		void		ft_hex_octet_minsize(char **a, t_struct *flags)
{
	char				*g;
	int					delta_size;

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
	if (flags->presizion == -1 && delta_size > 0)
		ft_hex_octet_minsizep2(a, flags, delta_size);
}

static	char			*ft_find_octet(char *av)
{
	unsigned long int	a;
	int					index;
	int					tmp[20];

	a = ft_atoi_long(av);
	if (a == 0)
		tmp[0] = 0;
	index = 0;
	while (a > 0)
	{
		tmp[index] = a % 8;
		a = a / 8;
		index++;
	}
	return (ft_print_octet(tmp, index - 1));
}

void					ft_print_o(va_list ap, t_struct *flags, char format)
{
	uint64_t			a;
	char				*k;
	char				*b;

	if (format == 'o')
		ft_take_unsigned_xo(&a, ap, flags);
	if (format == 'O')
		a = va_arg(ap, uint64_t);
	k = ft_itoa_long(a);
	if (k[0] == '0' && ft_strlen(k) == 1)
		b = k;
	else
	{
		b = ft_find_octet(k);
		ft_strdel(&k);
	}
	ft_octet_with_prezition(&b, a, flags);
	ft_hex_octet_minsize(&b, flags);
	write(1, b, ft_strlen(b));
	flags->write_count += ft_strlen(b);
	ft_strdel(&b);
}
