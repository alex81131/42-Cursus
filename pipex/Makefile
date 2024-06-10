# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 17:47:50 by kyeh              #+#    #+#              #
#    Updated: 2024/06/07 19:34:11 by kyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address
LIBC	= ar rcs

# Source files
SRC =	src/pipex.c \
		src/utils.c \
		libft+/libft.a

SRC_BONUS = \
		src_bonus/pipex_bonus.c \
		src_bonus/utils_bonus.c \
		libft+/lift.a

NAME	= pipex
RM		= rm -rf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}:
	make all -C libft+
	gcc $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	make clean -C libft+

fclean:
	$(RM) $(NAME)
	make fclean -C libft+

re:	fclean all

bonus:	fclean
	make all -C libft+
	gcc $(CFLAGS) $(SRC_BONUS) -o $(NAME)

.PHONY: all clean fclean re bonus