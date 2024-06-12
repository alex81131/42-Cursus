# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 17:47:50 by kyeh              #+#    #+#              #
#    Updated: 2024/06/12 12:34:44 by kyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address -g3
#LIBC	= ar rcs

# Source files
SRC =	src/push_swap.c \
		src/sort.c \
		src/utils.c \
		src/quicksort.c \
		src/op_push.c \
		src/op_rotate.c \
		src/op_rrotate.c \
		src/op_swap.c \
		libft+/libft.a

SRC_BONUS = \
		checker.c \
		libft+/libft.a

NAME	= push_swap
BONUS_NAME = checker
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

bonus:	
	make all -C libft+
	gcc $(CFLAGS) $(SRC_BONUS) -o $(BONUS_NAME)

.PHONY: all clean fclean re bonus