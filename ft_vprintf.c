/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:39:58 by dlancar           #+#    #+#             */
/*   Updated: 2016/01/09 17:03:00 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"
#include <stdarg.h>

void	ft_vprintf(const char *str, va_list ap)
{
	ft_vprintf_fd(STDOUT, str, ap);
}
