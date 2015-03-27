/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 16:01:19 by dlancar           #+#    #+#             */
/*   Updated: 2015/03/27 16:02:01 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "net.h"

void		socket_clean_fd(t_fd *fd)
{
	fd->type = SOC_FREE;
	fd->on_read = g_default_read;
	fd->on_write = g_default_write;
}
