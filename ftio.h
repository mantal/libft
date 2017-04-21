/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftio.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:56:18 by dlancar           #+#    #+#             */
/*   Updated: 2017/04/21 15:47:04 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTIO_H
# define FTIO_H

# include <stdbool.h>
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

# ifndef STDIN_FILENO
#  define STDIN_FILENO 0
# endif

# ifndef STDOUT_FILENO
#  define STDOUT_FILENO 1
# endif

# ifndef STDERR_FILENO
#  define STDERR_FILENO 2
# endif

# define STDIN  STDIN_FILENO
# define STDOUT STDOUT_FILENO
# define STDERR STDERR_FILENO

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
int				get_next(const int fd, char **line, char c);

# define FTIO_NONE    0
# define FTIO_ERROR   1
# define FTIO_WARNING 2
# define FTIO_INFO    3
# define FTIO_VERBOSE 4
# define FTIO_DEBUG   5

bool			debug(const char *s, ...);
bool			verbose(const char *s, ...);
bool			info(const char *s, ...);
bool			warning(const char *s, ...);
bool			error(const char *s, ...);

extern int		g_ftio_logsfd;
extern int		g_ftio_verbose_level;

typedef struct	s_iomap
{
	void	*p;
	size_t	size;
}				t_iomap;

int				ft_open(const char *path, int oflag, ...);
int				ft_close(int fd);

char			*io_map_file(int fd, int prot);
int				io_unmap_file(char *p);

extern bool		g_malloc_use;

/*
** TODO
*/

# define GT_BUFF_SIZE 100

typedef struct	s_sarray
{
	char			arr[GT_BUFF_SIZE];
	unsigned int	it;
	unsigned int	capacity;
}				t_sarray;

extern char		*g_path_root;

bool			path_is_valid(const char *path);
bool			path_is_valid_dir(const char *path);
char			*path_to_absolute(const char *path);
char			*path_join(const char *p1, const char *p2);
char			*path_sanitize(const char *path);

#endif
