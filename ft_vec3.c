/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 11:15:50 by dlancar           #+#    #+#             */
/*   Updated: 2017/04/20 15:19:59 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmath.h"

void	set_vec3(t_vec3 *vec, int x, int y, int z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

bool	vec3_cmp(const t_vec3 *vec1, const t_vec3 *vec2)
{
	if (vec1->x != vec2->x)
		return (false);
	if (vec1->y != vec2->y)
		return (false);
	if (vec1->z != vec2->z)
		return (false);
	return (true);
}
