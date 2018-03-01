/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:47:43 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/05 13:47:44 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static		void	ft_hex_with_prezition(char **a, uint64_t b, t_struct *flags)
{
	char			*src;

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
	if (flags->sharp == 1 && b != 0)
	{
		src = ft_strjoin("0x", *a);
		ft_strdel(a);
		*a = src;
	}
	if (b == 0 && flags->presizion == 0)
	{
		ft_strdel(&src);
		*a = ft_strnew(0);
	}
}

static		void	ft_hex_with_minsize2(char **a, t_struct *flags,\
										int delta_size)
{
	char			*g;

	g = ft_strnew(flags->min_size);
	if ((delta_size > 0 && flags->minus == '-') && (g = ft_strcpy(g, *a)))
		ft_memset(g + ft_strlen(*a), ' ', delta_size);
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
	else if (flags->minus != '-' && flags->zero == '0' && flags->sharp != 0)
	{
		g = ft_strcpy(g, "0x");
		ft_memset(g + 2, '0', delta_size);
		ft_strcat(g, (*a) + 2);
	}
	ft_strdel(a);
	*a = g;
}

static		void	ft_hex_with_minsize(char **a, t_struct *flags)
{
	char			*g;
	int				delta_size;

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
		ft_hex_with_minsize2(a, flags, delta_size);
}

void				ft_take_unsigned_xo(uint64_t *b, va_list ap,\
										t_struct *flags)
{
	if (flags->mod_size == 'z' || flags->mod_size == 'j' ||\
		flags->mod_size == 'L' || flags->mod_size == 'l')
		*b = va_arg(ap, uint64_t);
	else if (flags->mod_size == 'h')
		*b = (unsigned short int)va_arg(ap, void*);
	else if (flags->mod_size == 'H')
		*b = (unsigned char)va_arg(ap, void*);
	else
		*b = va_arg(ap, unsigned int);
}

void				ft_print_x(va_list ap, t_struct *flags, char format)
{
	uint64_t		a;
	char			*k;
	char			*b;

	ft_take_unsigned_xo(&a, ap, flags);
	k = ft_itoa_long(a);
	if (k[0] == '0' && ft_strlen(k) == 1)
		b = k;
	else
	{
		b = ft_find_hex(k);
		ft_strdel(&k);
	}
	ft_hex_with_prezition(&b, a, flags);
	ft_hex_with_minsize(&b, flags);
	ft_toapper_if_x(&b, format);
	write(1, b, ft_strlen(b));
	flags->write_count += ft_strlen(b);
	ft_strdel(&b);
}
