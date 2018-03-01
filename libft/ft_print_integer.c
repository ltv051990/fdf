/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 18:25:59 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/02 18:27:49 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void		ft_nbstr_with_prezition2(char **a, long long b,\
											t_struct *flags)
{
	char			*src;

	src = NULL;
	if (b < 0)
		src = ft_strjoin("-", *a);
	else if (b >= 0 && flags->plus == '+')
		src = ft_strjoin("+", *a);
	else if (flags->space == 1 && b >= 0 && flags->plus != '+')
		src = ft_strjoin(" ", *a);
	free(*a);
	*a = src;
}

static		void	ft_nbstr_with_prezition(char **a, long long b,\
											t_struct *flags)
{
	char			*tmp1;

	flags->count_nb = ft_search_dig((b >= 0 ? b : b * -1));
	flags->src = ft_itoa(b);
	if ((b < 0) && (tmp1 = ft_strdup(flags->src + 1)))
	{
		ft_strdel(&flags->src);
		flags->src = tmp1;
	}
	if ((flags->presizion > flags->count_nb) &&\
		(*a = ft_strnew(flags->presizion + 1)))
	{
		ft_memset(*a, '0', flags->presizion - flags->count_nb);
		*a = ft_strcat(*a, flags->src);
		free(flags->src);
	}
	else
		*a = flags->src;
	if (b < 0 || flags->plus == '+' || (flags->space == 1 && b >= 0 &&\
		flags->plus != '+'))
		ft_nbstr_with_prezition2(a, b, flags);
	if ((b == 0 && flags->presizion == 0) && (*a = ft_strnew(0)))
		ft_strdel(&flags->src);
}

static void			ft_take_di(long long int *b, va_list ap, t_struct *flags)
{
	if (flags->mod_size == 'z' || flags->mod_size == 'j' ||\
		flags->mod_size == 'L' || flags->mod_size == 'l')
		*b = va_arg(ap, long long);
	else if (flags->mod_size == 'h')
		*b = (short int)va_arg(ap, void*);
	else if (flags->mod_size == 'H')
		*b = (char)va_arg(ap, void*);
	else
		*b = va_arg(ap, int);
}

void				ft_print_integer(va_list ap, t_struct *flags)
{
	char			*a;
	long long int	b;

	ft_take_di(&b, ap, flags);
	ft_nbstr_with_prezition(&a, b, flags);
	ft_nbstr_with_minsize(&a, flags);
	write(1, a, ft_strlen(a));
	flags->write_count += ft_strlen(a);
	free(a);
}

void				ft_print_big_integer(va_list ap, t_struct *flags)
{
	char			*a;
	long long int	b;

	b = va_arg(ap, long int);
	ft_nbstr_with_prezition(&a, b, flags);
	ft_nbstr_with_minsize(&a, flags);
	write(1, a, ft_strlen(a));
	flags->write_count += ft_strlen(a);
	free(a);
}
