/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 11:17:32 by dlancar           #+#    #+#             */
/*   Updated: 2014/05/09 13:00:10 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

void	set_vec3d(t_vec3d *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

t_bool	vec3d_cmp(const t_vec3d *vec1, const t_vec3d *vec2)
{
	if (vec1->x != vec2->x)
		return (FALSE);
	if (vec1->y != vec2->y)
		return (FALSE);
	if (vec1->z != vec2->z)
		return (FALSE);
	return (TRUE);
}
