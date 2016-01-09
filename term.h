/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 16:33:48 by dlancar           #+#    #+#             */
/*   Updated: 2015/12/08 17:08:23 by dlancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** XTERM use VT100 codes
** other use ANSI codes
*/

#ifndef TERM_H
# define TERM_H

# ifndef XTERM
#  define CURSOR_UP   "\033[F"
#  define CURSOR_DOWN "\033[E"
# else
#  define CURSOR_UP   "\033[1A"
#  define CURSOR_DOWN "\033[1B"
# endif

# define CLEAR_LINE  "\033[K"

#endif
