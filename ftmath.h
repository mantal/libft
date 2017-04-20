/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 16:59:15 by dlancar           #+#    #+#             */
/*   Updated: 2017/04/20 15:18:34 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTMATH_H
# define FTMATH_H

# include "libft.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288419716939937510
# endif

# define ABS(X)     (((X) < 0) ? (-1 * (X)) : (X))
# define FMOD(N, D) ((N) - ((int)((N) / (D))) * (D))

typedef struct	s_vec3
{
	int		x;
	int		y;
	int		z;
}				t_vec3;

typedef struct	s_vec2
{
	int		x;
	int		y;
}				t_vec2;

typedef struct	s_vec3d
{
	double	x;
	double	y;
	double	z;
}				t_vec3d;

typedef struct	s_vec2d
{
	double	x;
	double	y;
}				t_vec2d;

int				ft_pow(int a, unsigned int n);
unsigned int	ft_sqrt(unsigned int n);
double			ft_sqrt_d(unsigned int n);

double			ft_trunc(double d, unsigned int p);
int				ft_round(double d);

double			ft_sin(double d);
double			ft_cos(double d);
double			ft_tan(double d);

void			set_vec2d(t_vec2d *vec, double x, double y);
void			set_vec3(t_vec3 *vec, int x, int y, int z);
void			set_vec3d(t_vec3d *vec, double x, double y, double z);
bool			vec2d_cmp(const t_vec2d *vec1, const t_vec2d *vec2);
bool			vec3_cmp(const t_vec3 *vec1, const t_vec3 *vec2);
bool			vec3d_cmp(const t_vec3d *vec1, const t_vec3d *vec2);

#endif
