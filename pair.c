/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:23:04 by dlancar           #+#    #+#             */
/*   Updated: 2017/02/10 16:25:27 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pair	*pair_new(void *a, void *b)
{
	t_pair	*pair;

	pair = ft_malloc(sizeof(t_pair));
	if (pair == NULL)
		return (NULL);
	pair_set(pair, a, b);
	return (pair);
}

t_pair	*pair_set(t_pair *pair, void *a, void *b)
{
	pair->a = a;
	pair->b = b;
	return (pair);
}
