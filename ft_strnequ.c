/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 09:31:47 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/12 15:30:32 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s2);
	if (ft_strlen(s1) > size && n > size)
		return (0);
	return (!ft_strncmp(s1, s2, n));
}
