/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:02:01 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/12 10:02:02 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_error(char *s)
{
	int		fd;
	char	*help;
	char	*a;

	a = "\x1b[33m\n\n\n";
	write(1, a, ft_strlen(a));
	if ((fd = open("dulia", O_RDONLY)))
	{
		while (get_next_line(fd, &help))
		{
			write(1, help, ft_strlen(help));
			write(1, "\n", 1);
			free(help);
		}
		close(fd);
	}
	a = "\x1b[31m ";
	a = ft_strjoin(a, s);
	write(1, a, ft_strlen(a));
	free(a);
	exit(0);
}

void		ft_usage(void)
{
	char	*a;

	a = "\x1b[33m\n\n\n";
	write(1, a, ft_strlen(a));
	a = "read usage\n";
	write(1, a, ft_strlen(a));
	exit(0);
}

static int	ft_is_basenb(char str)
{
	if ((str >= '0' && str <= '9') || (str >= 'A' && str <= 'F') ||\
		(str >= 'a' && str <= 'f'))
		return (1);
	return (0);
}

void		bad_color(char *a)
{
	int		count;
	int		hex_c;

	hex_c = 0;
	count = (int)ft_strlen(a);
	if (count < 3)
		ft_error("Bad color\n");
	if ((a[0] != '0') || (a[1] != 'x' && a[1] != 'X'))
		ft_error("Very bad color\n");
	a = a + 2;
	while (ft_is_basenb(*a))
	{
		hex_c++;
		a++;
	}
	if (hex_c > 8)
		ft_error("Bad color\n");
	if ((count - 2) != hex_c)
		ft_error("Bad color\n");
}

void		ft_def_stuct(t_all *uk)
{
	uk->x_angle = 0.2;
	uk->y_angle = 0.2;
	uk->z_angle = 0.2;
	uk->z_ofset = 1;
	uk->zoom = 20;
	uk->width = -1;
	uk->size = 1;
}
