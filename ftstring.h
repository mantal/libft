/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftstring.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 15:13:48 by dlancar           #+#    #+#             */
/*   Updated: 2017/02/21 14:49:08 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSTRING_H
# define FTSTRING_H

# include "libft.h"

char			*ft_strcat(char *s1, const char *s2);

const char		*ft_strchr(const char *s, int c);
const char		*ft_strnchr(const char *s, int c, size_t n);
const char		*ft_strrchr(const char *s, int c);
const char		*ft_strstr(const char *s1, const char *s2);
const char		*ft_strnstr(const char *s1, const char *s2, size_t n);
const char		*ft_strcharstr(const char *s1, const char *s2);
const char		*ft_strchar(const char *s1, const char *s2);

size_t			ft_strclen(const char *s, char c);
size_t			ft_strlen(const char *s);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strncpy(char *s1, const char *s2, size_t n);

char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s, size_t n);

int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strjoinf(char *s1, char *s2, t_flags flag);
char			*ft_strnjoin(const char *s1, const char *s2, size_t n);
char			*ft_strnjoinf(char *s1, char *s2, size_t n, t_flags flag);
char			*ft_strjoina(const char **s);

char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void			ft_strrpl(char *s, char c, char c2);

char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s);

t_array			*ft_strsplit(const char *s, char c);
t_array			*ft_strsplitstr(const char *s, const char *s1);

const char		*ft_strnstr(const char *s1, const char *s2, size_t n);

char			*ft_strmerge(const char **s);

bool			ft_strisdigit(const char *s);

#endif
