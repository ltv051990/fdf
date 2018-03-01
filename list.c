/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:13:46 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/12 10:13:46 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix		*lst_matr(char **split)
{
	t_matrix	*tmp;

	if ((tmp = ft_memalloc(sizeof(t_matrix))) == NULL)
		return (NULL);
	tmp->line = split;
	tmp->next = NULL;
	return (tmp);
}

void			lst_matr_pb(t_matrix **alst, t_matrix *new)
{
	t_matrix	*beg;

	if (!alst)
		return ;
	else if (!(*alst))
		*alst = new;
	else
	{
		beg = (*alst);
		while (beg->next)
			beg = beg->next;
		beg->next = new;
	}
}

void			change_color(t_all *uk)
{
	t_cord		*start;
	int			i;
	int			g;
	uint32_t	color;
	double		a;

	i = -1;
	g = uk->width * uk->height;
	a = 0.7;
	start = uk->cord_mw;
	while (++i < g)
	{
		color = start[i].color * a;
		if (color < 1000)
			color = 16777205;
		if (color > 16777214)
			color = 1000;
		start[i].color = color;
	}
}

void			ft_defolt_cord(t_all *uk)
{
	ft_copy_cord(uk);
	uk->zoom = 20;
	find_opt_zoom(uk);
	uk->x_ofset = 0;
	uk->y_ofset = 0;
	uk->z_ofset = 1;
	uk->x_angle = 0.2;
	uk->y_angle = 0.2;
	uk->z_angle = 0.2;
	uk->size = 1;
}

void			set_text(t_all *uk)
{
	mlx_string_put(uk->mlx, uk->win, 20, 20, 0x0000FF, "UDLR   - MOVE");
	mlx_string_put(uk->mlx, uk->win, 20, 40, 0xFFFF00, "8 2    - Rotate X");
	mlx_string_put(uk->mlx, uk->win, 20, 60, 0x0000FF, "+-     +- Z picks");
	mlx_string_put(uk->mlx, uk->win, 20, 80, 0xFFFF00, "4 6    - Rotate Y");
	mlx_string_put(uk->mlx, uk->win, 20, 100, 0x0000FF, "P     - Perspective");
	mlx_string_put(uk->mlx, uk->win, 20, 120, 0xFFFF00, "5     - Reset ALL");
	mlx_string_put(uk->mlx, uk->win, 20, 140, 0x0000FF, "0     - Change color");
	mlx_string_put(uk->mlx, uk->win, 20, 200, 0xFFFF00, ".     - Change color");
	mlx_string_put(uk->mlx, uk->win, 20, 160, 0xFFFF00, "+-(NL)- Change	zoom");
	mlx_string_put(uk->mlx, uk->win, 20, 180, 0x0000FF, "*     - Plot line");
}
