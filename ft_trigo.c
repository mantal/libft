/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trigo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 16:03:10 by dlancar           #+#    #+#             */
/*   Updated: 2014/05/09 13:01:17 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#define  _USE_MATH_DEFINES
#include <math.h>

extern double	g_sin[];
extern double	g_cos[];
extern double	g_tan[];

double	ft_sin(double d)
{
	d = d > 0 ? d : -d;
	d = d / (180 / M_PI);
	d = d > M_PI ? FMOD(d, M_PI) : d;
	d = ft_trunc(d, 2);
	d *= 1000;
	return (g_sin[(unsigned long long int)d]);
}

double	ft_cos(double d)
{
	d = d > 0 ? d : -d;
	d = d / (180 / M_PI);
	d = d > M_PI ? FMOD(d, M_PI * 2) : d;
	d = ft_trunc(d, 2);
	d *= 1000;
	return (g_cos[(unsigned long long int)d]);
}

double	ft_tan(double d)
{
	d = d > 0 ? d : -d;
	d = d / (180 / M_PI);
	d = d > M_PI ? FMOD(d, M_PI) : d;
	d = ft_trunc(d, 2);
	d *= 1000;
	return (g_tan[(unsigned long long int)d]);
}
