/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:44:04 by dlancar           #+#    #+#             */
/*   Updated: 2017/04/21 15:19:34 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"
#include "ftstring.h"
#include "libft.h"
#include <stdlib.h>

static char	*flatten(t_array *arr)
{
	t_array	res;
	char	**s;

	array_init(&res, sizeof(char), 0);
	array_add(&res, "/");
	arr->it = 0;
	while ((s = array_next(arr)) != NULL)
	{
		array_add_range(&res, *s, ft_strlen(*s));
		if (arr->it < arr->size)
			array_add(&res, "/");
	}
	array_add(&res, "");
	return (res.tab);
}

char		*path_join(const char *p1, const char *p2)
{
	char	*res;
	char	*tmp;

	res = ft_strjoina((const char *[]) { p1, "/", p2, NULL });
	tmp = res;
	res = path_sanitize(res);
	free(tmp);
	return (res);
}

char		*path_sanitize(const char *path)
{
	t_array	res;
	t_array	*dirs;
	char	**dir;
	char	*tmp;

	array_init(&res, sizeof(char *), 0);
	dirs = ft_strsplit(path, '/');
	while ((dir = array_next(dirs)) != NULL)
	{
		if (ft_strcmp(*dir, ".") == 0)
			continue ;
		if (ft_strcmp(*dir, "..") == 0 && res.size > 0
				&& ft_strcmp(*(char **)array_get(&res, res.size - 1), ".."))
			array_remove(&res, res.size - 1);
		else
			array_add(&res, dir);
	}
	tmp = flatten(&res);
	return (tmp);
}
