/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftio.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:56:18 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/09 17:07:19 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTIO_H
# define FTIO_H

# include <stdarg.h>
# include <stddef.h>

# define STDIN  STDIN_FILENO
# define STDOUT STDOUT_FILENO
# define STDERR STDERR_FILENO

# ifndef STDIN_FILENO
#  define STDIN_FILENO 0
# endif

# ifndef STDOUT_FILENO
#  define STDOUT_FILENO 1
# endif

# ifndef STDERR_FILENO
#  define STDERR_FILENO 2
# endif

void			ft_putchar(char c);
void			ft_putchar_fd(int fd, char c);

void			ft_putint(int n);
void			ft_putint_fd(int fd, int n);

void			ft_putubase_fd(int fd, unsigned long n, unsigned base);

void			ft_putstr(const char *s);
void			ft_putstr_fd(int fd, const char *s);

void			ft_putdouble(double d);
void			ft_putdouble_fd(int fd, double d);

void			ft_printf(const char *s, ...);
void			ft_printf_fd(int fd, const char *s, ...);

void			ft_vprintf(const char *s, va_list ap);
void			ft_vprintf_fd(int fd, const char *s, va_list ap);

int				ft_asprintf(char **s, const char *format, ...);

int				ft_get_next(const int fd, char **line, char c);

typedef struct	s_iomap
{
	void	*p;
	size_t	size;
}				t_iomap;

int				ft_open(const char *path, int oflag, ...);
int				ft_close(int fd);

char			*io_map_file(int fd, int prot);
int				io_unmap_file(char *p);

#endif
