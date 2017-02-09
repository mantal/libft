/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:47:36 by dlancar           #+#    #+#             */
/*   Updated: 2017/01/24 17:58:11 by dlancar          ###   ########.fr       */
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
	bool	(*validate)(const char **args, void *data);
	void	(*callback)(const char **args, void *data);
}				t_option;

int				options(const t_option *options, int argc,
		const char **argv, void *data);

#endif
