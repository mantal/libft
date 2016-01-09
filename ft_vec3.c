/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 11:15:50 by dlancar           #+#    #+#             */
/*   Updated: 2014/05/09 13:01:39 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

void	set_vec3(t_vec3 *vec, int x, int y, int z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

t_bool	vec3_cmp(const t_vec3 *vec1, const t_vec3 *vec2)
{
	if (vec1->x != vec2->x)
		return (FALSE);
	if (vec1->y != vec2->y)
		return (FALSE);
	if (vec1->z != vec2->z)
		return (FALSE);
	return (TRUE);
}
