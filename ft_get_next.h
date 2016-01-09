/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 13:05:49 by dlancar           #+#    #+#             */
/*   Updated: 2014/05/09 13:17:21 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_H
# define FT_GET_NEXT_H

typedef struct	s_entry
{
	struct s_entry	*next;
	int				fd;
	char			*buf;
}				t_entry;

#endif
