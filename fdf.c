/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 10:31:24 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/11 10:31:25 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		color_z(t_all *uk)
{
	t_cord	*start;
	int		i;
	int		g;

	i = -1;
	g = uk->width * uk->height;
	start = uk->cord_mw;
	while (++i < g)
	{
		if (start[i].z == 0)
			start[i].color = 0xFFFAFA;
		else if (start[i].z <= 10 && start[i].z > 0)
			start[i].color = 0xFFDEAD;
		else if (start[i].z <= 20 && start[i].z > 10)
			start[i].color = 0xFFFF00;
		else if (start[i].z > 20 && start[i].z <= 30)
			start[i].color = 0x6495ED;
		else if (start[i].z > 30 && start[i].z <= 40)
			start[i].color = 0x2E8B57;
		else if (start[i].z > 40)
			start[i].color = 0xFF0000;
	}
}

void		draw_line_low(t_all *uk, t_cord first, t_cord second,
							uint32_t color)
{
	uk->x0 = (first.x + uk->width / 2) * uk->zoom + uk->x_plus;
	uk->y0 = (first.y + uk->height / 2) * uk->zoom + uk->y_plus;
	uk->x1 = (second.x + uk->width / 2) * uk->zoom + uk->x_plus;
	uk->y1 = (second.y + uk->height / 2) * uk->zoom + uk->y_plus;
	uk->dx = uk->x1 - uk->x0;
	uk->dy = uk->y1 - uk->y0;
	uk->yi = 1;
	uk->x = uk->x0;
	uk->y = uk->y0;
	if (uk->dy < 0)
	{
		uk->yi = -1;
		uk->dy = -(uk->dy);
	}
	uk->b_d = 2 * uk->dy - uk->dx;
	while (uk->x++ != uk->x1)
	{
		mlx_pixel_put(uk->mlx, uk->win, uk->x, uk->y, first.color);
		if (uk->b_d > 0)
		{
			uk->y = uk->y + uk->yi;
			uk->b_d = uk->b_d - 2 * uk->dx;
		}
		uk->b_d = uk->b_d + 2 * uk->dy;
	}
}

void		draw_line_hight(t_all *uk, t_cord first, t_cord second,
							uint32_t color)
{
	uk->x0 = (first.x + uk->width / 2) * uk->zoom + uk->x_plus;
	uk->y0 = (first.y + uk->height / 2) * uk->zoom + uk->y_plus;
	uk->x1 = (second.x + uk->width / 2) * uk->zoom + uk->x_plus;
	uk->y1 = (second.y + uk->height / 2) * uk->zoom + uk->y_plus;
	uk->dx = uk->x1 - uk->x0;
	uk->dy = uk->y1 - uk->y0;
	uk->xi = 1;
	uk->x = uk->x0;
	uk->y = uk->y0;
	if (uk->dx < 0)
	{
		uk->xi = -1;
		uk->dx = -(uk->dx);
	}
	uk->b_d = 2 * uk->dx - uk->dy;
	while (uk->y++ != uk->y1)
	{
		mlx_pixel_put(uk->mlx, uk->win, uk->x, uk->y, first.color);
		if (uk->b_d > 0)
			uk->x = uk->x + uk->xi;
		if (uk->b_d > 0)
			uk->b_d = uk->b_d - 2 * uk->dy;
		uk->b_d = uk->b_d + 2 * uk->dx;
	}
}

void		draw_line(t_cord first, t_cord second, uint32_t color, t_all *uk)
{
	uk->x0 = (first.x + uk->width / 2) * uk->zoom + uk->x_plus;
	uk->y0 = (first.y + uk->height / 2) * uk->zoom + uk->y_plus;
	uk->x1 = (second.x + uk->width / 2) * uk->zoom + uk->x_plus;
	uk->y1 = (second.y + uk->height / 2) * uk->zoom + uk->y_plus;
	if ((uk->x0 < 0 || uk->x0 >= D_WIDTH || uk->y0 < 0 || uk->y0 >= D_HEIGHT)
		&& (uk->x1 < 0 || uk->x1 >= D_WIDTH || uk->y1 < 0
			|| uk->y1 >= D_HEIGHT))
		return ;
	if ((abs(uk->y1 - uk->y0)) < (abs(uk->x1 - uk->x0)))
	{
		if (uk->x0 > uk->x1)
			draw_line_low(uk, second, first, color);
		else
			draw_line_low(uk, first, second, color);
	}
	else
	{
		if (uk->y0 > uk->y1)
			draw_line_hight(uk, second, first, color);
		else
			draw_line_hight(uk, first, second, color);
	}
}

int			main(int argc, char **argv)
{
	t_all	*uk;
	int		fd;

	uk = ft_memalloc(sizeof(t_all));
	ft_def_stuct(uk);
	if (argc < 2 || argc > 2)
		ft_usage();
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error("Bad file\n");
	ft_read(uk, fd);
	ft_fill_struct(uk);
	uk->mlx = mlx_init();
	uk->win = mlx_new_window(uk->mlx, D_WIDTH, D_HEIGHT, "FDF");
	find_opt_zoom(uk);
	ft_picture_draw(uk);
	mlx_hook(uk->win, 2, 5, ft_keys, uk);
	mlx_loop(uk->mlx);
	return (0);
}
