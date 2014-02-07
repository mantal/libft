/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 16:31:12 by dlancar           #+#    #+#             */
/*   Updated: 2014/02/07 13:05:27 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_array		*ft_strsplitstr(const char *s, const char *s1)
{
	t_array		*res;
	int			i;
	char		*temp;

	(res = array_new(100, 10, sizeof(char *), PTR), i = 0);
	while (*s)
	{
		while (*s && ft_strchr(s1, *s))
			s++;
		while (s[i] && !ft_strchr(s1, s[i]))
			i++;
		if (!*s)
			return (res);
		temp = ft_strndup(s, i);
		if (!temp)
		{
			array_free(&res);
			return (NULL);
		}
		array_add(res, temp);
		(s += i, i = 0);
	}
	return (res);
}

/*
t_array		*ft_strsplitstr(const char *s, const char *s1)
{
	t_array		*res;
	int		i;
	t_uint		j;
	char		*temp;

	(res = array_new(100, 10, sizeof(char *), PTR), i = 0, j = 0);
	while (*s)
	{
		while (*s && ft_strchr(s1, *s))
			s++;
		if (!*s)
			return (res);
		while (j < ft_strlen(s1))
		{
			if ((int)(ft_strchr(s, s1[j]) - s) < i)
				i = (int)(ft_strchr(s, s1[j]) - s);
			//i = (ft_strrchr(s, s1[j]) > i) ? ft_strrchr(s, s1[j]) : i;
			j++;
		}
		i = (!i) ? ft_strlen(s) : i;
		temp = ft_strndup(s, i);
		if (!temp)
		{
			array_free(&res);
			return (NULL);
		}
		array_add(res, temp);
		(s += i, i = 0, j = 0);
	}
	return (res);
}*/
/*
t_array		*ft_strsplitstr(const char *s, const char *s1)
{
	t_array	*res;
	char	*temp;
	t_uint		i;
	t_uint		j;

	(res = array_new(100, 10, sizeof(char *), PTR), i = 0, j = 0);
	while (*s)
	{
		while (ft_strchr(s1, *s))
			s++;
		if (!*s)
			return (res);
		while (j < ft_strlen(s1))
			(i = (ft_strclen(s, s1[j]) > i) ? ft_strclen(s, s1[j]) : i, j++);
		(temp = ft_strndup(s, i), j = 0);
		if (!temp)
		{
			array_free(&res);
			return (NULL);
		}
		array_add(res, temp);
		(s += i, i = 0);
	}
	return (res);
}*/

