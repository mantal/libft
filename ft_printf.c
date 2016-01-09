/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:39:58 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/09 17:02:45 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"
#include <stdarg.h>

void	ft_printf(const char *str, ...)
{
	va_list		ap;

	va_start(ap, str);
	ft_vprintf(str, ap);
	va_end(ap);
}
