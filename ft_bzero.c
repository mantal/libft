/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 09:31:47 by dlancar           #+#    #+#             */
/*   Updated: 2013/11/28 10:40:16 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*this_var_only_exist_to_compile_when_ptr_arithmetic_is_disabled;

	if (!s)
		return ;
	i = 0;
	this_var_only_exist_to_compile_when_ptr_arithmetic_is_disabled = (char*)s;
	while (i < n)
	{
		*this_var_only_exist_to_compile_when_ptr_arithmetic_is_disabled = 0;
		this_var_only_exist_to_compile_when_ptr_arithmetic_is_disabled++;
		i++;
	}
}
