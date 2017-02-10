/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:41:27 by dlancar           #+#    #+#             */
/*   Updated: 2017/02/10 16:43:07 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftstring.h"
#include <stdlib.h>

void	*map_get(t_map *map, const char *key)
{
	t_pair	*p;

	map->arr.it = 0;
	while ((p = array_next(&map->arr)))
	{
		if (ft_strcmp(p->a, key) == 0)
			return (p->b);
	}
	return (NULL);
}

void	map_free(t_map *map)
{
	free(map);
}
