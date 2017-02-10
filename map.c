/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:15:22 by dlancar           #+#    #+#             */
/*   Updated: 2017/02/10 19:19:29 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftstring.h"

t_map	*map_new(void)
{
	t_map	*map;

	map = ft_malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map_init(map);
	return (map);
}

t_map	*map_init(t_map *map)
{
	array_init(&map->arr, sizeof(t_pair), 0);
	return (map);
}

t_map	*map_set(t_map *map, const char *key, void *data)
{
	t_pair	*p;

	map->arr.it = 0;
	while ((p = array_next(&map->arr)))
	{
		if (ft_strcmp(p->a, key) == 0)
		{
			p->b = data;
			return (map);
		}
	}
	return (NULL);
}

t_map	*map_insert(t_map *map, const char *key, void *data)
{
	char	*dkey;

	if (map_get(map, key) != NULL)
		return (NULL);
	dkey = ft_strdup(key);
	if (dkey == NULL)
		return (NULL);
	array_add(&map->arr, (t_pair[]) { (t_pair){ .a = dkey, .b = data } });
	return (map);
}

t_map	*map_remove(t_map *map, const char *key)
{
	t_pair	*p;

	map->arr.it = 0;
	while ((p = array_next(&map->arr)))
	{
		if (ft_strcmp(p->a, key) == 0)
		{
			array_remove(&map->arr, map->arr.it - 1);
			return (map);
		}
	}
	return (NULL);
}
