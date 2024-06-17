# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 18:42:47 by kyeh              #+#    #+#              #
#    Updated: 2024/06/17 18:48:40 by kyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address
LIBC	= ar rcs

# Source files
SRC =	src/fdf.c \
		src/utils.c \
		src/utils_error.c \

# Object files
OBJ = $(SRC:.c=.o)

NAME	= fdf
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

.PHONY: all libft+/libft.a clean fclean re