/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 09:48:45 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/12 15:24:03 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	return (!ft_strcmp(s1, s2));
}
