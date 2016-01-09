/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 09:41:14 by dlancar           #+#    #+#             */
/*   Updated: 2014/03/09 16:43:59 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>

# ifndef NULL
#  define NULL ((void *)0)
# endif

# define STDIN  0
# define STDOUT 1
# define STDERR 2

# define TRUE  1
# define FALSE 0

# define NAF   3

# define PTR  2
# define LOOP 4

# define LOAD_FACTOR 0.75

# define BUFF_SIZE 32

typedef unsigned char	t_bool;
typedef unsigned int	t_flags;
typedef unsigned int	t_uint;

typedef struct	s_array
{
	void			*tab;
	size_t			size;
	size_t			capacity;
	size_t			size_change;
	size_t			size_type;
	unsigned int	it;
	t_flags			flags;
}				t_array;

t_array			*array_new(size_t capacity, size_t size_change,
						size_t size_type, t_flags flags);
t_array			*array_cpy(const t_array *src);
t_array			*array_add(t_array *arr, void *value);
t_array			*array_set(t_array *arr, void *value, unsigned int index);
t_array			*array_insert(t_array *arr, void *value, unsigned int index);
t_array			*array_remove(t_array *arr, unsigned int index);
t_array			*array_clear(t_array *arr, t_bool b);
t_array			*array_resize(t_array *arr, t_bool auto_resize);
void			*array_get(t_array *arr, unsigned int index);
void			*array_next(t_array *arr);
void			array_free(t_array **arr);

# define A_G(arr, index) array_get(arr, index)
# define A_N(arr) array_next(arr)

# define A_GI(arr, index)  (*(int *)array_get(arr, index))
# define A_GUI(arr, index) (*(unsigned int *)array_get(arr, index))

# define A_C(arr, index)  (*(char *)A_G(arr, index))
# define A_S(arr, index)  (*(char **)A_G(arr, index))

int				ft_atoi(const char *str);
char			*ft_itoa(int n);

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

void			ft_bzero(void *s, size_t n);
void			*ft_malloc(size_t size);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memset(void *b, int c, size_t len);

size_t			ft_get_size(int n);

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(const char *s);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
int				ft_putuint_base(unsigned int n, unsigned int base);
int				ft_putuint_base_l(unsigned int n, unsigned int base);
void			ft_putstr(const char *s);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putfstr(const char *s1, const void *arg);
void			ft_putdouble(double d);
void			ft_putdouble_fd(double d, int fd);
void			ft_printf(const char *s, ...);
void			ft_printf_fd(int fd, const char *s, ...);
void			ft_vprintf(const char *s, va_list ap);
void			ft_vprintf_fd(int fd, const char *s, va_list ap);

char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchar(const char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcharstr(const char *s1, const char *s2);
size_t			ft_strclen(const char *s, char c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *s1, const char *s2);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strjoinf(char *s1, char *s2, t_flags flag);
char			*ft_strnjoin(const char *s1, const char *s2, size_t n);
char			*ft_strnjoinf(char *s1, char *s2, size_t n, t_flags flag);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *s1, const char *s2, size_t n);
char			*ft_strndup(const char *s, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s);
t_array			*ft_strsplit(const char *s, char c);
t_array			*ft_strsplitstr(const char *s, const char *s1);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
int				ft_snprintf(char *s, size_t n, const char *format, ...);

int				ft_get_next(const int fd, char **line, char c);

char			*get_env(const char *name);
char			*get_path(int index);

#endif
