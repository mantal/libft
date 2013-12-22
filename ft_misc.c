/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 14:24:03 by dlancar           #+#    #+#             */
/*   Updated: 2013/12/22 18:43:57 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_i(void *data, const void *value, t_uint index, t_flags type)
{
	if (type & CHAR)
		*((char*)data + index) = *(char*)value;
	else if (type & UCHAR)
		*((unsigned char*)data + index) = *(unsigned char*)value;
	else if (type & SHORT)
		*((short*)data + index) = *(short*)value;
	else if (type & USHORT)
		*((unsigned short*)data + index) = *(unsigned short*)value;
	else if (type & INT)
		*((int*)data + index) = *(int*)value;
	else if (type & UINT)
		*((unsigned int*)data + index) = *(unsigned int*)value;
	else if (type & LINT)
		*((long int*)data + index) = *(long int*)value;
	else if (type & ULINT)
		*((unsigned long int*)data + index) = *(unsigned long int*)value;
	else if (type & LLINT)
		*((long long int*)data + index) = *(long long int*)value;
	else if (type & ULLINT)
		*((unsigned long long int*)data + index) =
			*(unsigned long long int*)value;
	else if (type & DOUBLE)
		*((double*)data + index) = *(double*)value;
	else if (type & FLOAT)
		*((float*)data + index) = *(float*)value;

}

void	ft_set(void *data, const void *value, t_flags type)
{
	if (type & CHAR)
		*(char*)data = *(char*)value;
	else if (type & UCHAR)
		*(unsigned char*)data = *(unsigned char*)value;
	else if (type & SHORT)
		*(short*)data = *(short*)value;
	else if (type & USHORT)
		*(unsigned short*)data = *(unsigned short*)value;
	else if (type & INT)
		*(int*)data = *(int*)value;
	else if (type & UINT)
		*(unsigned int*)data = *(unsigned int*)value;
	else if (type & LINT)
		*(long int*)data = *(long int*)value;
	else if (type & ULINT)
		*(unsigned long int*)data = *(unsigned long int*)value;
	else if (type & LLINT)
		*(long long int*)data = *(long long int*)value;
	else if (type & ULLINT)
		*(unsigned long long int*)data = *(unsigned long long int*)value;
	else if (type & DOUBLE)
		*(double*)data = *(double*)value;
	else if (type & FLOAT)
		*(float*)data = *(float*)value;
}

