/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:11:53 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/12 15:55:39 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"
#include "libft.h"

int		ft_isprint(int c)
{
	if (c == '\0')
		return (0);
	if (ft_isalnum(c) || ft_strchr(" !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~", c))
		return (1);
	return (0);
}
