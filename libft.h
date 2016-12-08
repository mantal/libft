/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:15:49 by dlancar           #+#    #+#             */
/*   Updated: 2016/12/08 14:51:03 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

# define PTR  2

# define BUFF_SIZE 32

typedef unsigned int	t_flags;

typedef struct	s_array
{
	void			*tab;
	size_t			size;
	size_t			capacity;
	size_t			capacity_change;
	size_t			size_type;
	unsigned int	it;
	t_flags			flags;
}				t_array;

t_array			*array_new(size_t size_type, t_flags flags);
t_array			*array_init(t_array *arr, size_t size_type, t_flags flags);
t_array			*array_cpy(const t_array *src);
t_array			*array_add(t_array *arr, const void *value);
t_array			*array_set(t_array *arr, void *value, size_t index);
t_array			*array_insert(t_array *arr, void *value, size_t index);
t_array			*array_remove(t_array *arr, size_t index);
t_array			*array_clear(t_array *arr);
t_array			*array_resize(t_array *arr);
void			*array_get(const t_array *arr, size_t index);
void			*array_next(t_array *arr);
void			array_free(t_array *arr);

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
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memset(void *b, int c, size_t len);

size_t			count_digit(unsigned int n);
size_t			count_digit_base(unsigned int n, unsigned int base);

char			*get_env(const char *name);
char			*get_path(int index);

#endif
