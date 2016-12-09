/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:47:36 by dlancar           #+#    #+#             */
/*   Updated: 2016/12/09 17:46:30 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# include "stdbool.h"

typedef struct	s_option
{
	char	**names;
	char	*usage;
	int		args_n;
	bool	(*validate)(const char **args);
	void	(*callback)(const char **args);
}				t_option;

int				options(const t_option *options, int argc,
		const char **argv);

#endif
