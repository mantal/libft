/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 16:59:15 by dlancar           #+#    #+#             */
/*   Updated: 2014/01/04 13:59:01 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "libft.h"

# define ABS(X)     (((X) < 0) ? (-1 * (X)) : (X))
# define FMOD(N, D) ((N) - ((int)((N) / (D))) * (D))

typedef struct	s_vec3
{
	int		x;
	int		y;
	int		z;
}				t_vec3;

typedef struct	s_vec3d
{
	double	x;
	double	y;
	double	z;
}				t_vec3d;

/*
** Basic math operations
*/
int		ft_pow(int a, unsigned int n);
t_uint	ft_sqrt(t_uint n);
double	ft_sqrt_d(t_uint n);

/*
** Double operations
*/
double	ft_trunc(double d, t_uint p);
int		ft_round(double d);

/*
** Trigonometric function
*/
double	ft_sin(double d);
double	ft_cos(double d);
double	ft_tan(double d);

/*
** Vector operation
*/
void	set_vec3(t_vec3 *vec, int x, int y, int z);
void	set_vec3d(t_vec3d *vec, double x, double y, double z);
t_bool	vec3_cmp(const t_vec3 *vec1, const t_vec3 *vec2);
t_bool	vec3d_cmp(const t_vec3d *vec1, const t_vec3d *vec2);

#endif /* !FT_MATH_H */

