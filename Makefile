# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+       #
#    By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2013/11/29 09:40:24 by dlancar           #+#    #+#              #
#    Updated: 2016/12/02 18:15:05 by dlancar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c 		\
			ft_memchr.c ft_memcmp.c ft_malloc.c								\
																			\
			ft_strdup.c ft_strlen.c										 	\
			ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c 				\
			ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strncmp.c 	\
			ft_strnstr.c ft_strcmp.c ft_strndup.c ft_strclen.c ft_strjoin.c	\
			ft_strtrim.c ft_strchar.c ft_striter.c ft_strmap.c				\
			ft_striteri.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c	\
			ft_strjoinf.c ft_strnjoin.c ft_strnjoinf.c ft_strsplit.c 		\
			ft_strsplitstr.c ft_strisdigit.c ft_strmerge.c ft_strrpl.c		\
																			\
			ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c				\
			ft_isdigit.c ft_isalnum.c ft_isalpha.c ft_isspace.c				\
																			\
			ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c			\
			ft_putint.c ft_putint_fd.c										\
			ft_putdouble.c ft_putdouble_fd.c ft_printf.c					\
			ft_vprintf.c ft_vprintf_fd.c ft_printf_fd.c ft_asprintf.c 		\
			ft_putubase_fd.c log.c											\
																			\
			ft_atoi.c ft_itoa.c												\
																			\
			ft_math.c ft_vec3.c ft_vec3d.c ft_double.c ft_vec2d.c			\
																			\
			ft_get_next.c													\
																			\
			ft_array.c ft_array_2.c	ft_array_3.c							\
																			\
			ft_error.c														\
																			\
			count_digit.c													\
																			\
			ft_config.c														\
																			\
			socket.c socket_utils.c socket_var.c select.c					\
																			\
			cbuffer.c cbuffer_2.c											\
																			\
			io.c malloc_.c realloc_.c free_.c mem.c							\
																			\
			args.c

OBJ		= $(SRC:.c=.o)
CMP		= clang
FLAGS	= -Wall -Wextra -O0 -g3 -Wmissing-prototypes -std=c11


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CMP) -o $@ -c $? $(FLAGS)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

suicide: fclean
	@rm -f $(SRC)
