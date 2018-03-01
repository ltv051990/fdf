/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:59:03 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/12 17:59:09 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void			ft_read(t_all *uk, int fd)
{
	char		*line;
	char		**split;
	int			res;
	int			ret;

	while ((ret = get_next_line(fd, &line)))
	{
		if (ret < 0)
			ft_error("Very bad file\n");
		++uk->height;
		res = ft_split_cw(line, ' ', &split);
		lst_matr_pb(&uk->mnext, lst_matr(split));
		if (uk->width == -1)
			uk->width = res;
		else
		{
			if (res != uk->width)
			{
				free(line);
				ft_error("Bad width\n");
			}
		}
		free(line);
	}
	close(fd);
}

void			ft_cor_str(t_all *uk, int x, int y, char *beg)
{
	char		**dst;
	int			res;

	res = ft_split_cw(beg, ',', &dst);
	if (res > 2 || res < 1)
		ft_error("Error in picsel cord\n");
	uk->cord_df[x + y * uk->width].x = (double)x - uk->width / 2;
	uk->cord_df[x + y * uk->width].y = (double)y - uk->height / 2;
	uk->cord_df[x + y * uk->width].z = (double)ft_atoi(*dst);
	if (res == 1)
		uk->cord_df[x + y * uk->width].color = 0xFFFFFF;
	if (res == 2)
	{
		bad_color(dst[1]);
		uk->cord_df[x + y * uk->width].color = ft_atoi_base(dst[1] + 2, 16);
		if (uk->cord_df[x + y * uk->width].color == 0)
			free(dst[1]);
	}
	free(dst[0]);
	free(dst);
}

void			ft_copy_cord(t_all *uk)
{
	t_cord		*start;
	t_cord		*dst;
	int			i;
	int			g;

	i = -1;
	g = uk->width * uk->height;
	start = uk->cord_df;
	dst = uk->cord_mw;
	while (++i < g)
	{
		dst[i].x = start[i].x;
		dst[i].y = start[i].y;
		dst[i].z = start[i].z;
		dst[i].color = start[i].color;
	}
}

void			ft_fill_struct(t_all *uk)
{
	t_matrix	*start;
	char		**beg;
	int			y;
	int			x;

	y = 0;
	x = 0;
	uk->cord_mw = ft_memalloc(sizeof(t_cord) * ((uk->width * uk->height)));
	uk->cord_df = ft_memalloc(sizeof(t_cord) * ((uk->width * uk->height)));
	uk->cord_bf = ft_memalloc(sizeof(t_cord) * ((uk->width * uk->height)));
	start = uk->mnext;
	while (start)
	{
		beg = start->line;
		while (beg[x])
		{
			ft_cor_str(uk, x, y, beg[x]);
			x++;
		}
		x = 0;
		y++;
		start = start->next;
	}
	ft_copy_cord(uk);
}

void			find_opt_zoom(t_all *uk)
{
	while (uk->zoom > 0)
	{
		if (uk->height * uk->zoom < (((D_HEIGHT - 100) / 5) * 4) &&
			uk->width * uk->zoom < (((D_WIDTH - 100) / 5) * 4))
			break ;
		uk->zoom -= 1;
	}
	if (uk->zoom == 0)
		uk->zoom = 1;
}
