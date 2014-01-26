/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 15:14:37 by dlancar           #+#    #+#             */
/*   Updated: 2014/01/17 18:04:14 by dlancar          ###   ########.fr       */
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

t_flags		error_opt(t_flags flags);
void		*ft_error(void);
void		*ft_error_msg(const char *msg, ...);

#endif /* !ERROR_H */
