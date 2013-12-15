/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:18:04 by dlancar           #+#    #+#             */
/*   Updated: 2013/11/22 11:18:05 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#if defined(_WIN32) || defined(__WIN32__)
 #include <io.h>
#else
 #include <unistd.h>
#endif

void	ft_putendl(const char *s)
{
	write(STDOUT, s, ft_strlen(s));
	write(STDOUT, "\n", 1);
}

