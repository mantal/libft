/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 10:28:00 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/12 15:45:41 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"
#include "libft.h"
#include <stdlib.h>

char	*ft_strnjoinf(char *s1, char *s2, size_t n, t_flags flag)
{
	char	*res;

	res = ft_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	ft_bzero(res, sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strncat(res, s2, n);
	if (flag & 1)
		free(s1);
	if (flag & 2)
		free(s2);
	return (res);
}
