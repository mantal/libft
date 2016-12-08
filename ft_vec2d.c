/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 16:30:54 by dlancar           #+#    #+#             */
/*   Updated: 2016/12/08 14:53:06 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

void	set_vec2d(t_vec2d *vec, double x, double y)
{
	vec->x = x;
	vec->y = y;
}

bool	vec2d_cmp(const t_vec2d *vec1, const t_vec2d *vec2)
{
	if (vec1->x == vec2->y && vec1->y == vec2->y)
		return (true);
	return (false);
}
