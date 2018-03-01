/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 22:26:26 by tlutsyk           #+#    #+#             */
/*   Updated: 2017/10/26 22:28:29 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 32
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

# define S1(p) (p == 's' || p == 'S' || p == 'p' || p == 'd' || p == 'D')

# define S2(o) (o == 'o' || o == 'O' || o == 'u' || o == 'U' || o == 'x')

# define S3(i) (i == 'X' || i == 'c' || i == 'C' || i == 'i' || i == '%')

# define SPEC_PER(x) (S1(x) || S2(x) || S3(x))

# define FLAGS_SIZE(y) (y == 'h' || y == 'l' || y == 'j' || y == 'z')

# define FM1(u) (u == '#' || u == '0' || u ==  '-')

# define FM2(y) (y == '+' || y == ' ' || y == '.')

# define FL_MODIF(a) (FM1(a) || FM2(a))

# define FLAGS(w) (w == '#' || w ==  '-' || w ==  '+' || w == ' ')

# define INFRM(z) (!SPEC_PER(z) && !FL_MODIF(z) && !FLAGS_SIZE(z) && z != '\0')

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_struct
{
	int				min_size;
	int				presizion;
	int				print_size;
	int				sharp;
	int				space;
	char			plus;
	char			minus;
	char			zero;
	char			mod_size;
	int				write_count;
	char			*string;
	int				count_nb;
	int				un_costil;
	char			char_costil;
	int				size;
	char			*src;
}					t_struct;

int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isascii(int c);
int					ft_atoi(const char *str);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, \
					size_t len);
char				*ft_strnew(size_t size);
char				*ft_itoa(long long int n);
char				*ft_itoa_long(uint64_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				ft_strdel(char **s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(long long int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_memdel(void **ap);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void	const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*ft_realloc(void *ptr, size_t size);
char				*ft_strjoin_def(char *s1, char *s2);
char				*ft_strcalc(char *src);
int					ft_sqrt(int nb);
int					ft_power(int nb, int power);
void				ft_list_push_back(t_list **alst, t_list *new);
int					ft_split_cw(char const *s, char c, char ***dest);
int64_t				ft_atoi_base(char *str, int base);

/*
*** ft_printf
*/

uint64_t			ft_atoi_long(char *str);
char				*ft_print_hex(int *tmp, int index);
char				*ft_find_hex(char *av);
int					ft_presizion_s(t_struct *flags, int size_argum);
int					ft_min_pole_s(t_struct *flags, int size_argum);
void				ft_print_s(va_list ap, t_struct *flags, int prapor);
void				ft_print_c(char alpha, t_struct *flags);
void				ft_start_read_c(char format, va_list ap, t_struct *flags);
void				ft_print_p(va_list ap, t_struct *flags);
void				ft_print_unicode_char(va_list ap, t_struct *flags);
void				ft_unic_string(va_list ap, t_struct *flags);
int					count_bite(unsigned int nb);
int					ft_cur_max(unsigned int *a, t_struct *flags);
void				ft_putchar_un(unsigned int nb);
void				ft_print_integer(va_list ap, t_struct *flags);
void				ft_print_big_integer(va_list ap, t_struct *flags);
void				ft_undigit(va_list ap, t_struct *flags);
void				ft_un_big_digit(va_list ap, t_struct *flags);
void				ft_print_x(va_list ap, t_struct *flags, char format);
void				ft_print_o(va_list ap, t_struct *flags, char format);
void				ft_take_unsigned_xo(uint64_t *b, va_list ap,
										t_struct *flags);
void				ft_presizion_memory(t_struct *flags, char **a, uint64_t b);
char				*ft_print_octet(int *tmp, int index);
void				ft_toapper_if_x(char **a, char x);
size_t				ft_search_un(uint64_t nb);
size_t				ft_search_dig(long long int nb);
void				ft_take_ud(uint64_t *b, va_list ap, t_struct *flags);
void				ft_nbstr_with_minsize(char **a, t_struct *flags);
void				ft_defolt_struct(t_struct *flags);
void				ft_print_argument(char format, va_list ap, t_struct *flags);
int					ft_read_nbsize_flags(char *format, t_struct *flags);
void				ft_start_read(char *format, va_list ap, t_struct *flags);
int					ft_read_spec_start(char *format, va_list ap,
										t_struct *flags);
int					ft_read_spec(char *format, t_struct *flags, int index);
int					ft_wr_fls(char mod, t_struct *flags);
int					ft_printf(const char *format, ...);

/*
*** GNL
*/

int					get_next_line(const int fd, char **line);

#endif
