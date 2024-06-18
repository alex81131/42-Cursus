# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 17:47:50 by kyeh              #+#    #+#              #
#    Updated: 2024/06/18 16:38:30 by kyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address -g3
#LIBC	= ar rcs

# Source files
SRC =	src/push_swap.c \
		src/qs_utils.c \
		src/utils.c \
		src/quicksort.c \
		src/op_push.c \
		src/op_rotate.c \
		src/op_rrotate.c \
		src/op_swap.c

SRC_BONUS = \
		src_bonus/checker.c

# Object files
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJ_NOMAIN = ${filter-out src/push_swap.o, $(OBJ)}

NAME	= push_swap
BONUS_NAME = checker
RM		= rm -rf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): libft+/libft.a $(OBJ)
	gcc $(CFLAGS) $(OBJ) libft+/libft.a -o $(NAME)

all: $(NAME)

libft+/libft.a:
	make -C libft+

clean:
	make clean -C libft+
	$(RM) $(OBJ) $(OBJ_BONUS) $(OBJ_NOMAIN)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	make fclean -C libft+

re:	fclean all

bonus:	$(NAME) $(OBJ_BONUS)
	gcc $(CFLAGS) $(OBJ_NOMAIN) $(OBJ_BONUS) libft+/libft.a -o $(BONUS_NAME)

.PHONY: all libft+/libft.a clean fclean re bonus