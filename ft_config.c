/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:56:57 by dlancar           #+#    #+#             */
/*   Updated: 2017/04/20 17:11:43 by dlancar          ###   ########.fr       */
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

char	*get_path(int index)
{
	static t_array	*path = NULL;

	if (!path)
		path = ft_strsplit(get_env("PATH"), ':');
	if (index < 0)
	{
		array_free(path);
		return (NULL);
	}
	if ((unsigned int)index >= path->size)
		return (NULL);
	return (*(char **)array_get(path, index));
}
