# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+       #
#    By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2013/11/29 09:40:24 by dlancar           #+#    #+#              #
#    Updated: 2014/02/06 18:30:11 by dlancar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c 		\
			ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c ft_malloc.c	\
																			\
			ft_strnew.c ft_strdel.c ft_strclr.c ft_strdup.c ft_strlen.c 	\
			ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c 				\
			ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strncmp.c 	\
			ft_strnstr.c ft_strcmp.c ft_strndup.c ft_strclen.c ft_strjoin.c	\
			ft_strtrim.c ft_strchar.c ft_striter.c ft_strmap.c				\
			ft_striteri.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c	\
			ft_snprintf.c ft_strjoinf.c ft_strnjoin.c ft_strsplit.c			\
			ft_strcharstr.c	ft_strsplitstr.c								\
																			\
			ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c				\
			ft_isdigit.c ft_isalnum.c ft_isalpha.c ft_isspace.c				\
																			\
			ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c			\
			ft_putnbr.c ft_putnbr_fd.c ft_putendl.c ft_putendl_fd.c			\
			ft_putdouble.c ft_putdouble_fd.c ft_printf.c ft_putfstr.c		\
			ft_vprintf.c ft_vprintf_fd.c ft_printf_fd.c ft_putint_base.c	\
																			\
			ft_atoi.c ft_itoa.c												\
																			\
			ft_math.c ft_vec3.c ft_vec3d.c ft_math_cst.c ft_double.c		\
			ft_trigo.c ft_vec2d.c											\
																			\
			ft_get_next.c													\
																			\
			ft_array.c ft_array_2.c											\
																			\
			ft_error.c														\
																			\
			ft_get_size.c													\
																			\
			ft_config.c

OBJ		= $(SRC:.c=.o)
CMP		= cc #llvm-gcc
FLAGS	= -Wall -Werror -Wextra -O0 -g -Wmissing-prototypes


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CMP) -I. -o $@ -c $? $(FLAGS)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

suicide: fclean
	@rm -f $(SRC)
