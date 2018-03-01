/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 14:39:48 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/25 14:39:50 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_read_spec(char *format, t_struct *flags, int index)
{
	index = 0;
	while (format[index] != '\0' && !(SPEC_PER(format[index])))
	{
		if ((FLAGS(format[index])) && (ft_wr_fls(format[index], flags)))
			index++;
		if (format[index] == '0' && ++index)
			flags->zero = '0';
		if (ft_isdigit(format[index]))
			flags->min_size = flags->min_size > ft_atoi(&format[index])\
			? flags->min_size : ft_atoi(&format[index]);
		while (ft_isdigit(format[index]))
			index++;
		if (format[index] == '.' && ft_isdigit(format[index + 1]))
			flags->presizion = ft_atoi(&format[++index]);
		if (format[index] == '.' && !(ft_isdigit(format[index + 1])) && ++index)
			flags->presizion = 0;
		while (ft_isdigit(format[index]))
			index++;
		if (FLAGS_SIZE(format[index]))
			index += ft_read_nbsize_flags(&format[index], flags);
		if ((format[index] == '\0') || ((INFRM(format[index]))))
			break ;
	}
	return (index);
}

void			ft_start_read_c(char format, va_list ap, t_struct *flags)
{
	char	alpha;

	if (flags->mod_size == 'l')
	{
		ft_print_unicode_char(ap, flags);
		return ;
	}
	if (format != '\0')
		alpha = format;
	else
		alpha = va_arg(ap, int);
	ft_print_c(alpha, flags);
}

/*
*** one loop to read my format string
*/

int				ft_read_spec_start(char *format, va_list ap, t_struct *flags)
{
	int			ind;
	int			index;

	ind = 0;
	index = 0;
	ind = ft_read_spec(format, flags, index);
	if (INFRM(format[ind]))
		ft_start_read_c(format[ind], ap, flags);
	else if (SPEC_PER(format[ind]))
	{
		if (format[ind] == '%')
			ft_start_read_c('%', ap, flags);
		else
			ft_print_argument(format[ind], ap, flags);
	}
	ft_defolt_struct(flags);
	return (ind);
}

void			ft_start_read(char *format, va_list ap, t_struct *flags)
{
	int			index;

	index = 0;
	while (*format != '\0' && flags->un_costil == 1)
	{
		while (*format && *format != '%' && ++(flags->write_count))
			ft_putchar(*format++);
		if (*format == '%' && format++)
		{
			if (*format == '\0')
				return ;
			index = ft_read_spec_start(format, ap, flags);
			if (*(format + index) == '\0')
				return ;
			else
				format = format + index + 1;
		}
	}
}

/*
*** inizial struct and inizial va_arg
*/

int				ft_printf(const char *format, ...)
{
	t_struct	flags;
	va_list		ap;

	flags.write_count = 0;
	flags.un_costil = 1;
	va_start(ap, format);
	ft_defolt_struct(&flags);
	if (*format == '\0')
		return (0);
	ft_start_read((char *)format, ap, &flags);
	va_end(ap);
	if (flags.un_costil == -1)
		return (-1);
	return (flags.write_count);
}
