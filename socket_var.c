/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 16:39:40 by dlancar           #+#    #+#             */
/*   Updated: 2015/03/27 16:06:45 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "net.h"

int			(*g_default_accept)(t_socket *, int) = socket_accept;
int			(*g_default_read)() = (void *)0;
int			(*g_default_write)() = (void *)0;

void		socket_set_default_accept(int (*def_accept)(t_socket *, int))
{
	g_default_accept = def_accept;
}

void		socket_set_default_read(int (*def_read)())
{
	g_default_read = def_read;
}

void		socket_set_default_write(int (*def_write)())
{
	g_default_write = def_write;
}