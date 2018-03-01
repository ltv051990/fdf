/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_picture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 21:18:39 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/16 21:18:40 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_picture_draw(t_all *uk)
{
	t_cord	*start;
	t_cord	pix;
	t_cord	*end;
	int		i;
	int		g;

	i = -1;
	g = uk->width * uk->height;
	start = uk->cord_mw;
	end = uk->cord_bf;
	uk->y_plus = (D_HEIGHT / 2 - (uk->height * uk->zoom) / 2)
				+ uk->zoom + uk->y_ofset;
	uk->x_plus = (D_WIDTH / 2 - (uk->width * uk->zoom) / 2)
				+ uk->zoom + uk->x_ofset;
	while (++i < g)
	{
		pix = start[i];
		ft_move_pixel(uk, &pix);
		mlx_pixel_put(uk->mlx, uk->win, (pix.x + uk->width / 2) * uk->zoom
	+ uk->x_plus, (pix.y + uk->height / 2) * uk->zoom + uk->y_plus, pix.color);
		end[i] = pix;
	}
	if (uk->cost == 0)
		ft_draw_image(uk);
	set_text(uk);
}

void		ft_move_pixel(t_all *uk, t_cord *pixel)
{
	double	x;
	double	y;

	pixel->x *= uk->size;
	pixel->y *= uk->size;
	pixel->z *= uk->size * uk->z_ofset;
	y = pixel->y;
	pixel->y = pixel->y * cos(uk->x_angle) - pixel->z * sin(uk->x_angle);
	pixel->z = y * sin(uk->x_angle) + pixel->z * cos(uk->x_angle);
	x = pixel->x;
	pixel->x = pixel->x * cos(uk->y_angle) + pixel->z * sin(uk->y_angle);
	pixel->z = -1 * (x * sin(uk->y_angle)) + pixel->z * cos(uk->y_angle);
	pixel->x *= uk->size;
	pixel->y *= uk->size;
	pixel->z *= uk->size;
}

void		ft_draw_image(t_all *uk)
{
	t_cord	*end;
	int		x;
	int		y;

	x = 0;
	y = 0;
	end = uk->cord_bf;
	while (y < uk->height)
	{
		if (x + 1 < uk->width)
			draw_line(end[x + y * uk->width], end[(x + 1) + y * uk->width],
				end[x + y * uk->width].color, uk);
		if (y + 1 < uk->height)
			draw_line(end[x + y * uk->width], end[(x + (y + 1) * uk->width)],
				end[x + y * uk->width].color, uk);
		x++;
		if (x == uk->width)
		{
			x = 0;
			y++;
		}
		if (y == uk->height)
			break ;
	}
}

void		ft_keys_2(int key, t_all *uk)
{
	if (key == 82)
		color_z(uk);
	if (key == 65)
		change_color(uk);
	if (key == 91)
		uk->x_angle += 0.1;
	if (key == 84)
		uk->x_angle -= 0.1;
	if (key == 86)
		uk->y_angle += 0.1;
	if (key == 88)
		uk->y_angle -= 0.1;
	if (key == 87)
		ft_defolt_cord(uk);
	if (key == 67)
		uk->cost = (uk->cost == 0) ? (1) : (0);
}

int			ft_keys(int key, t_all *uk)
{
	if (key == 53)
		exit(0);
	ft_keys_2(key, uk);
	if (key == 124)
		uk->x_ofset += 5;
	if (key == 123)
		uk->x_ofset -= 5;
	if (key == 126)
		uk->y_ofset -= 5;
	if (key == 125)
		uk->y_ofset += 5;
	if (key == 69)
		uk->size = uk->size > 1.8 ? uk->size : uk->size * 1.1;
	if (key == 78)
		uk->size = uk->size < 0.5 ? uk->size : uk->size / 1.1;
	if (key == 24)
		uk->z_ofset = uk->z_ofset > 2 ? uk->z_ofset : uk->z_ofset + 0.1;
	if (key == 27)
		uk->z_ofset = uk->z_ofset < -2 ? uk->z_ofset : uk->z_ofset - 0.1;
	mlx_clear_window(uk->mlx, uk->win);
	ft_picture_draw(uk);
	return (0);
}
