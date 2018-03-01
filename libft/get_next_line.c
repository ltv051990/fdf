/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:22:44 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/12/13 16:22:45 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_search_fd(t_list **begin_list, int fd, t_list **find)
{
	if (!(*begin_list))
	{
		*begin_list = ft_lstnew(NULL, 0);
		(*begin_list)->content_size = fd;
		*find = *begin_list;
		return ;
	}
	*find = *begin_list;
	while (*find)
	{
		if (fd == (int)(*find)->content_size)
			return ;
		*find = (*find)->next;
	}
	*find = ft_lstnew(NULL, 0);
	(*find)->content_size = fd;
	ft_lstadd(begin_list, *find);
}

static int	ft_read(char **musorok, int fd)
{
	int		read_count;
	size_t	beg;
	char	*dst;

	if (*musorok == NULL)
		*musorok = ft_strnew(BUFF_SIZE);
	while (ft_strchr(*musorok, '\n') == NULL)
	{
		dst = ft_strnew(ft_strlen(*musorok) + BUFF_SIZE);
		ft_strcpy(dst, *musorok);
		ft_strdel(musorok);
		*musorok = dst;
		beg = ft_strlen(*musorok);
		read_count = read(fd, &(*musorok)[beg], BUFF_SIZE);
		if (read_count < 0)
			return (-1);
		if ((*musorok)[beg] == '\0' && read_count == 0)
			return (0);
	}
	return (1);
}

static int	check(char **musorok, char **line)
{
	char *find;
	char *dst;

	dst = NULL;
	find = ft_strchr(*musorok, '\n');
	*line = ft_strsub(*musorok, 0, find - (*musorok));
	dst = ft_strsub(find + 1, 0, ft_strlen(find) - 1);
	free(*musorok);
	*musorok = dst;
	return (1);
}

static int	ft_find(char **musorok, int fd, char **line)
{
	int		bla;

	if (*musorok == NULL || ft_strchr(*musorok, '\n') == NULL)
	{
		if ((bla = ft_read(musorok, fd)) == 0)
		{
			if (ft_strchr(*musorok, '\n') != NULL)
				return (check(musorok, line));
			else if (ft_strchr(*musorok, '\n') == NULL && *(*musorok) != '\0')
			{
				*line = ft_strdup(*musorok);
				ft_strdel(musorok);
				return (1);
			}
			else
			{
				ft_strdel(musorok);
				return (0);
			}
		}
		else if (bla == -1)
			return (-1);
	}
	return (check(musorok, line));
}

int			get_next_line(const int fd, char **line)
{
	static	t_list	*start;
	t_list			*find;
	char			*tmp;
	int				res;

	if (fd >= 0 && line != NULL && BUFF_SIZE > 0)
	{
		ft_search_fd(&start, fd, &find);
		tmp = (char *)find->content;
		res = ft_find(&tmp, fd, line);
		find->content = (void*)tmp;
		return (res);
	}
	return (-1);
}
