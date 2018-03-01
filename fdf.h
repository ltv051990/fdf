/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 10:31:09 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/11 10:31:11 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# define D_WIDTH 1600
# define D_HEIGHT 1200

typedef struct		s_matrix
{
	char			**line;
	struct s_matrix	*next;
}					t_matrix;

typedef struct		s_cord
{
	double			x;
	double			y;
	double			z;
	int32_t			color;
}					t_cord;

typedef struct		s_all
{
	int64_t			height;
	int64_t			width;
	void			*mlx;
	void			*win;
	double			y_ofset;
	double			x_ofset;
	double			z_ofset;
	t_matrix		*mnext;
	t_cord			*cord_df;
	t_cord			*cord_mw;
	t_cord			*cord_bf;
	double			x_angle;
	double			y_angle;
	double			z_angle;
	uint8_t			zoom;
	double			size;
	double			y_plus;
	double			x_plus;
	int8_t			cost;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				dx;
	int				dy;
	int				xi;
	int				yi;
	int				x;
	int				y;
	int				b_d;
}					t_all;

void				ft_keys_2(int key, t_all *uk);
int					ft_keys(int key, t_all *uk);
void				color_z(t_all *uk);
void				draw_line(t_cord first, t_cord second, uint32_t color,
								t_all *uk);
void				ft_move_pixel(t_all *uk, t_cord *pixel);
void				ft_draw_image(t_all *uk);
void				ft_picture_draw(t_all *uk);
void				set_text(t_all *uk);
void				ft_defolt_cord(t_all *uk);
void				change_color(t_all *uk);
void				ft_def_stuct(t_all *uk);
void				ft_error(char *s);
void				ft_usage(void);
void				print(t_all *uk);
t_matrix			*lst_matr(char **split);
void				lst_matr_pb(t_matrix **alst, t_matrix *new);
void				bad_color(char *a);
void				ft_read(t_all *uk, int fd);
void				ft_cor_str(t_all *uk, int x, int y, char *beg);
void				ft_fill_struct(t_all *uk);
void				ft_copy_cord(t_all *uk);
void				find_opt_zoom(t_all *uk);
void				set_text(t_all *uk);

#endif
