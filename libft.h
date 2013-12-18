/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 09:41:14 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/18 16:12:17 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define BUFF_SIZE 32

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define TRUE 1
# define FALSE 0

# define LOAD_FACTOR 0.75

# define CHAR 2
# define UCHAR 4
# define SHORT 8
# define USHORT 16
# define INT 32
# define UINT 64
# define LINT 128
# define ULINT 256
# define LLINT 512
# define ULLINT 1028
# define DOUBLE 2048
# define FLOAT 4096

typedef unsigned char	t_bool;
typedef unsigned int	t_flags;
typedef unsigned int	t_uint;

typedef struct	s_array
{
	char	*tab;
	size_t	size;
	size_t	capacity;
	size_t	size_change;
	size_t	size_type;
	t_flags	flags;
}				t_array;

/*
** Dynamic array function
*/

t_array	*array_new_c(size_t capacity, size_t size_change, size_t size_type,
						t_flags flags);
t_array	*array_add(t_array *arr, void* value);
t_array	*array_set(t_array *arr, void *value, unsigned int index);
t_array	*array_resize(t_array *arr, t_bool auto_resize);
void	array_free(t_array **arr);

/*
** Conversion function
*/
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

/*
** Character function
*/
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

/*
** Memory operation
*/
void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	ft_memdel(void **ap);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memset(void *b, int c, size_t len);

/*
** Math function
*/
int		ft_pow(int x, unsigned int n);
size_t	ft_get_size(int n);

/*
** Display function
*/
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(const char *s);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putint_base(unsigned int n, unsigned int base);
void	ft_putstr(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putfstr(const char *s1, const void *arg);
void	ft_putdouble(double d);
void	ft_putdouble_fd(double d, int fd);
void	ft_printf(const char *s, ...);

/*
** String function
*/
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchar(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strcharstr(const char *s1, const char *s2);
size_t	ft_strclen(const char *s, char c);
void	ft_strclr(char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *s1, const char *s2);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
int		ft_strequ(char const *s1, char const *s2);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strndup(const char *s, size_t n);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char 	*ft_strnew(size_t size);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strsub(const char *s, unsigned int start, size_t len);
char	*ft_strtrim(const char *s);
char	**ft_strsplit(const char *s, char c);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
int		ft_snprintf(char *s, size_t n, const char *format, ...);
char	*ft_strnjoin(const char *s1, const char *s2, size_t n);
char	*ft_strjoinf(char *s1, char *s2, unsigned char flag);

/*
** File read function
*/
int		ft_get_next(const int fd, char **line, char c);

/*
** Misc functions
** ft_set and ft_set_i may be useless and could be replaced with ft_memcpy.
*/
void	ft_set(void *data, const void *value, t_flags type);
void	ft_set_i(void *data, const void *value, t_uint index, t_flags flags);

#endif /* !LIBFT_H */

