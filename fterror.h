/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fterror.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 15:14:37 by dlancar           #+#    #+#             */
/*   Updated: 2017/02/24 12:13:52 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTERROR_H
# define FTERROR_H

# include "libft.h"
# include <errno.h>

# define ERR_DISP_NONE		1
# define ERR_DISP_PERROR	2
# define ERR_DISP_AUTO		4
# define ERR_EXIT			8
# define ERR_FORCE_CRASH	16

extern t_flags	g_error_flags;

int			ft_error(void);
int			ft_error_msg(const char *msg, ...);
const char	*ft_strerror(int errnum);
int			ft_derror(int fd, const char *msg, ...);

#endif
