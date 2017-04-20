/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:15:49 by dlancar           #+#    #+#             */
/*   Updated: 2017/04/20 17:11:56 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

# define BUFF_SIZE 32

typedef unsigned int	t_flags;

# define ARR_FREE_CONTENT  2
# define ARR_FREE_ON_CLEAR 4

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
t_array			*array_add_range(t_array *arr, void *values, size_t n);
t_array			*array_set(t_array *arr, void *value, size_t index);
t_array			*array_insert(t_array *arr, void *value, size_t index);
t_array			*array_remove(t_array *arr, size_t index);
t_array			*array_clear(t_array *arr);
t_array			*array_resize(t_array *arr);
void			*array_get(const t_array *arr, size_t index);
void			*array_prev(t_array *arr);
void			*array_next(t_array *arr);
t_array			*array_free_content(t_array *arr);
void			array_free(t_array *arr);

typedef struct	s_map
{
	t_array	arr;
}				t_map;

t_map			*map_new(void);
t_map			*map_init(t_map *map);
t_map			*map_set(t_map *map, const char *key, void *value);
t_map			*map_insert(t_map *map, const char *key, void *value);
t_map			*map_remove(t_map *map, const char *key);
void			*map_get(t_map *map, const char *key);
void			map_free(t_map *map);

typedef struct	s_pair
{
	void	*a;
	void	*b;
}				t_pair;

t_pair			*pair_new(void *a, void *b);
t_pair			*pair_set(t_pair *pair, void *a, void *b);

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

/*
** if g_malloc_use == true use system malloc, else use ours.
*/
extern bool		g_malloc_use;

void			ft_bzero(void *s, size_t n);
void			*ft_malloc(size_t size);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
const void		*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memset(void *b, int c, size_t len);

size_t			count_digit(unsigned int n);
size_t			count_digit_base(unsigned int n, unsigned int base);

char			*get_env(const char *name);
void			env_set(const char *key, const char *value);
char			*get_path(unsigned int index);

#endif
