# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 17:47:50 by kyeh              #+#    #+#              #
#    Updated: 2024/06/17 18:26:50 by kyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address
LIBC	= ar rcs

# Source files
SRC =	src/pipex.c \
		src/utils.c \
		src/utils_error.c \

SRC_BONUS = \
		src_bonus/pipex_bonus.c \
		src_bonus/utils_bonus.c \
		src_bonus/utils_error_bonus.c \

# Object files
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME	= pipex
RM		= rm -rf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: libft+/libft.a $(OBJ) 
	gcc $(CFLAGS) $(OBJ) libft+/libft.a -o $(NAME)

all: $(NAME)

libft+/libft.a:
	make -C libft+

clean:
	make clean -C libft+
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft+

re:	fclean all

bonus:	libft+/libft.a $(OBJ_BONUS)
	gcc $(CFLAGS) $(OBJ_BONUS) libft+/libft.a -o $(NAME)

.PHONY: all libft+/libft.a clean fclean re bonus