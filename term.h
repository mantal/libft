/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 16:33:48 by dlancar           #+#    #+#             */
/*   Updated: 2016/12/09 17:40:23 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_H
# define TERM_H

/*
** XTERM use VT100 codes
** other use ANSI codes
*/

# ifndef XTERM
#  define CURSOR_UP   "\033[F"
#  define CURSOR_DOWN "\033[E"
# else
#  define CURSOR_UP   "\x1B[1A"
#  define CURSOR_DOWN "\x1B[1B"
# endif

# define CURSOR_SET(x, y) (ft_printf("\e[%d,%dH", (x), (y)))

# define CURSOR_HOME "\x1B[H"

# define CLEAR_LINE  "\x1B[K"
# define CLEAR       "\x1B[2J\x1B[H"

# define KNRM    "\x1B[0m"
# define RED     "\x1B[31m"
# define GREEN   "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE    "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN    "\x1B[36m"
# define WHITE   "\x1B[37m"

# define RESET   "\x1B[0m"

#endif
