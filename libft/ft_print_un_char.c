/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_un_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 15:50:23 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/30 15:50:24 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*** print UNISCODE char from 2048 < <65536 && > 65536
*/

static void			ft_putchar_un_2part(unsigned int nb, unsigned int mask,\
									unsigned int v, unsigned char res)
{
	unsigned int	mask_tmp;

	if (nb < 65536)
	{
		mask_tmp = (mask >> 5) << 5;
		res = (v >> 12) | mask_tmp;
		write(1, &res, 1);
		mask_tmp = ((mask >> 7) << 7);
		res = ((v << 20) >> 26) | mask_tmp;
		write(1, &res, 1);
		res = ((v << 26) >> 26) | mask_tmp;
		write(1, &res, 1);
	}
	else
	{
		res = (v >> 18) | mask;
		write(1, &res, 1);
		mask_tmp = ((mask >> 7) << 7);
		res = ((v << 14) >> 26) | mask_tmp;
		write(1, &res, 1);
		res = ((v << 20) >> 26) | mask_tmp;
		write(1, &res, 1);
		res = ((v << 26) >> 26) | mask_tmp;
		write(1, &res, 1);
	}
}

/*
*** print UNISCODE char from 0 < <128 && < 2048
*/

void				ft_putchar_un(unsigned int nb)
{
	unsigned int	mask;
	unsigned int	mask_tmp;
	unsigned int	v;
	unsigned char	res;

	mask = 240;
	v = nb;
	res = 0;
	if (nb < 128)
	{
		res = nb;
		write(1, &res, 1);
	}
	else if (nb < 2048)
	{
		mask_tmp = (mask >> 6) << 6;
		res = (v >> 6) | mask_tmp;
		write(1, &res, 1);
		mask_tmp = ((mask >> 7) << 7);
		res = ((v << 26) >> 26) | mask_tmp;
		write(1, &res, 1);
	}
	else
		ft_putchar_un_2part(nb, mask, v, res);
}

/*
*** return nb bits in count
*/

int					count_bite(unsigned int nb)
{
	if (nb < 128)
		return (1);
	else if (nb < 2048)
		return (2);
	else if (nb < 65536)
		return (3);
	return (4);
}

/*
*** change outputs when min_size != 0
*/

static void			ft_print_un_char_ms(unsigned int a, \
					t_struct *flags, int min_size)
{
	if (flags->minus == '-')
	{
		ft_putchar_un(a);
		while (min_size--)
			write(1, " ", 1);
	}
	else
	{
		while (min_size--)
			write(1, " ", 1);
		ft_putchar_un(a);
	}
}

/*
*** change outputs with flags
*/

void				ft_print_unicode_char(va_list ap, t_struct *flags)
{
	unsigned int	a;
	int				nb_bite;
	int				min_size;

	a = va_arg(ap, unsigned int);
	if (ft_cur_max(&a, flags) == -1)
		return ;
	nb_bite = count_bite(a);
	min_size = ft_min_pole_s(flags, nb_bite);
	flags->write_count += nb_bite + min_size;
	if (min_size != 0)
		ft_print_un_char_ms(a, flags, min_size);
	else
		ft_putchar_un(a);
}
