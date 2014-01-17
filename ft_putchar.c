/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:16:20 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/04 10:32:05 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#if defined(_WIN32) || defined(__WIN32__)
# include <io.h>
#else
# include <unistd.h>
#endif

void	ft_putchar(char c)
{
	write(STDOUT, &c, 1);
}
