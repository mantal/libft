/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:15:49 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/18 16:45:29 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

# define NAF   3

# define PTR  2
# define LOOP 4

# define LOAD_FACTOR 0.75

# define BUFF_SIZE 32

typedef bool			t_bool;
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
t_array			*array_new_s(size_t size_type);
t_array			*array_new_sp(size_t size_type);
t_array			*array_init(t_array *arr, size_t capacity, size_t size_type,
						t_flags flags);
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
