/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:14:01 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/27 14:14:03 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*** there i find precision
*/

int			ft_presizion_s(t_struct *flags, int size_argum)
{
	if (flags->presizion == -1)
		return (size_argum);
	if (flags->presizion < 0)
		return (0);
	if (size_argum > flags->presizion)
		return (flags->presizion);
	return (size_argum);
}

/*
*** print string with min_size and precision
*/

static void	ft_printf_s_with_size(t_struct *flags, int length, int min_size)
{
	flags->write_count += length + min_size;
	if (min_size != 0)
	{
		if (flags->minus == '-')
		{
			write(1, flags->string, length);
			while (min_size--)
				write(1, " ", 1);
		}
		else if (flags->zero == '\0')
		{
			while (min_size--)
				write(1, " ", 1);
			write(1, flags->string, length);
		}
		else if (flags->zero == '0')
		{
			while (min_size--)
				write(1, "0", 1);
			write(1, flags->string, length);
		}
	}
	else
		write(1, flags->string, length);
}

/*
*** before print a strinf, I'm finding a min output size and precision
*/

void		ft_print_s(va_list ap, t_struct *flags, int prapor)
{
	int		length;
	int		min_size;

	if (flags->mod_size == 'l')
	{
		ft_unic_string(ap, flags);
		return ;
	}
	if (prapor == 1)
		flags->string = "(null)";
	else if ((flags->string = va_arg(ap, char *)) == NULL)
		flags->string = "(null)";
	length = ft_presizion_s(flags, ft_strlen(flags->string));
	min_size = ft_min_pole_s(flags, length);
	ft_printf_s_with_size(flags, length, min_size);
}

static void	ft_print_cms(char lala, int min_size, t_struct *flags)
{
	char	alpha;

	alpha = lala;
	if (flags->minus == '-')
	{
		write(1, &alpha, 1);
		while (min_size--)
			write(1, " ", 1);
	}
	else if (flags->zero == '\0')
	{
		while (min_size--)
			write(1, " ", 1);
		write(1, &alpha, 1);
	}
	else if (flags->zero == '0')
	{
		while (min_size--)
			write(1, "0", 1);
		write(1, &alpha, 1);
	}
}

/*
*** print char with min_size and precision
*/

void		ft_print_c(char alpha, t_struct *flags)
{
	int		min_size;

	min_size = ft_min_pole_s(flags, 1);
	flags->write_count += 1 + min_size;
	if (min_size != 0)
		ft_print_cms(alpha, min_size, flags);
	else
		write(1, &alpha, 1);
}
