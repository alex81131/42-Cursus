# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 15:23:21 by kyeh              #+#    #+#              #
#    Updated: 2024/05/17 15:39:45 by kyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_printf_number_hex.c\
			ft_printf_ptr.c ft_printf_unsigned_int.c\
			ft_printf_int_decimal.c
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
LIBC	= ar rcs
CC		= cc -Wall -Wextra -Werror
RM		= rm -f

.c.o:
	${CC} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re