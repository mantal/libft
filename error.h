/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 15:14:37 by dlancar           #+#    #+#             */
/*   Updated: 2014/06/21 13:10:54 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"
# include <errno.h>

# define ERR_DISP_NONE   1
# define ERR_DISP_PERROR 2
# define ERR_DISP_AUTO   4
# define ERR_FATAL       8

# define ERR_GET         3

# define ERR_DEF		 ERR_DISP_AUTO | ERR_FATAL

t_flags		error_opt(t_flags flags);
int			ft_error(void);
int			ft_error_msg(const char *msg, ...);
int			ft_perror(void);

#endif

