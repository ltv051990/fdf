/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 22:05:20 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/09 22:05:21 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*** after outputs spec -> defoult struct flags
*/

void	ft_defolt_struct(t_struct *flags)
{
	flags->min_size = -1;
	flags->presizion = -1;
	flags->print_size = 0;
	flags->space = -1;
	flags->plus = '\0';
	flags->minus = '\0';
	flags->zero = '\0';
	flags->sharp = 0;
	flags->mod_size = '\0';
	flags->count_nb = 0;
	flags->char_costil = '\0';
	flags->size = 0;
	flags->src = NULL;
}

/*
*** when i find a spec start modul.functions
*/

void	ft_print_argument(char format, va_list ap, t_struct *flags)
{
	if (format == 's')
		ft_print_s(ap, flags, 0);
	if ((format == 'c' || format == '%') && (flags->char_costil = format))
		ft_start_read_c('\0', ap, flags);
	if (format == 'p')
		ft_print_p(ap, flags);
	if (format == 'S')
		ft_unic_string(ap, flags);
	if (format == 'C')
		ft_print_unicode_char(ap, flags);
	if (format == 'd' || format == 'i')
		ft_print_integer(ap, flags);
	if (format == 'D')
		ft_print_big_integer(ap, flags);
	if (format == 'o' || format == 'O')
		ft_print_o(ap, flags, format);
	if (format == 'u')
		ft_undigit(ap, flags);
	if (format == 'U')
		ft_un_big_digit(ap, flags);
	if (format == 'x' || format == 'X')
		ft_print_x(ap, flags, format);
}

int		ft_read_nbsize_flags(char *format, t_struct *flags)
{
	int	a;

	a = 1;
	if (*format == 'z' && (a = 1))
		flags->mod_size = 'z';
	else if (*format == 'j' && flags->mod_size != 'z' && (a = 1))
		flags->mod_size = 'j';
	else if (*format == 'l' && *(format + 1) == 'l' && \
		flags->mod_size != 'j' && flags->mod_size != 'z' && (a = 2))
		flags->mod_size = 'L';
	else if (*format == 'l' && flags->mod_size != 'L' && \
		flags->mod_size != 'j' && flags->mod_size != 'z' && (a = 1))
		flags->mod_size = 'l';
	else if (*format == 'h' && *(format + 1) != 'h' &&\
		flags->mod_size != 'l' && flags->mod_size != 'L' \
		&& flags->mod_size != 'j' && flags->mod_size != 'z' && (a = 1))
		flags->mod_size = 'h';
	else if (*format == 'h' && *(format + 1) == 'h' &&\
		flags->mod_size != 'h' && flags->mod_size != 'l' \
		&& flags->mod_size != 'L' && flags->mod_size != 'j'\
		&& flags->mod_size != 'z' && (a = 2))
		flags->mod_size = 'H';
	return (a);
}

/*
*** read spec and write them to struct
*/

int		ft_wr_fls(char mod, t_struct *flags)
{
	if (mod == ' ')
		flags->space = 1;
	if (mod == '#')
		flags->sharp = 1;
	if (mod == '-')
		flags->minus = '-';
	if (mod == '+')
		flags->plus = '+';
	return (1);
}
