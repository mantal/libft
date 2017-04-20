/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:56:57 by dlancar           #+#    #+#             */
/*   Updated: 2017/04/20 17:29:52 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"
#include "libft.h"

char	*get_env(const char *name)
{
	extern char	**environ;
	int			i;
	size_t		size;

	i = 0;
	size = ft_strlen(name);
	while (environ[i])
	{
		if (ft_strcmp(environ[i], name) == '=')
			return (environ[i] + size + 1);
		i++;
	}
	return (NULL);
}

/*
** TODO fix leaks
*/

void	env_set(const char *key, const char *value)
{
	extern char	**environ;
	t_array		arr;
	int			i;
	const char	*tmp = get_env(key);

	if (tmp == NULL)
	{
		array_init(&arr, sizeof(char *), 0);
		while (environ[arr.it] != NULL)
			array_add(&arr, &environ[arr.it++]);
		array_add(&arr, (char *[]) {
					ft_strjoina((const char *[]) { key, "=", value, NULL }) });
		array_add(&arr, (char *[]) { NULL });
		environ = arr.tab;
		return ;
	}
	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_strcmp(environ[i], key) == '=')
			environ[i] = ft_strjoina((const char*[]) { key, "=", value, NULL });
		i++;
	}
}

/*
** TODO fix leaks
*/

void	env_remove(const char *key)
{
	extern char	**environ;
	t_array		arr;
	const char	*target = get_env(key);

	if (target == NULL)
		return ;
	array_init(&arr, sizeof(char *), 0);
	while (environ[arr.it] != NULL)
	{
		if (environ[arr.it] != target)
			array_add(&arr, &environ[arr.it]);
		arr.it++;
	}
	environ = arr.tab;
}

char	*get_path(unsigned int index)
{
	t_array	*path;
	char	*s;

	s = get_env("PATH");
	if (s == NULL)
		return (NULL);
	path = ft_strsplit(s, ':');
	if ((size_t)index >= path->size)
		return (NULL);
	return (*(char **)array_get(path, index));
}
