# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 18:42:47 by kyeh              #+#    #+#              #
#    Updated: 2024/06/26 18:59:24 by kyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
NOCOL=\033[0m
RED=\033[1;31m
YEL=\033[1;33m
ORG=\033[0;33m
GRN=\033[1;32m
DGRAY=\033[1;30m
BLU=\033[1;34m

# Compiler and flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CCFLAGS = -Wall -Wextra -Werror
LIBC	= ar rcs

CCFLAGS += -D WIN_H=720 -D WIN_W=1280
#CCFLAGS += -D WIN_H=1080 -D WIN_W=1920
CFLAGS += -D BUFFER_SIZE=10
#CFLAGS += -D BUFFER_SIZE=500
CFLAGS += -O3
CCFLAGS += -O3
#CFLAGS += -fsanitize=address -g3
#CCFLAGS += -fsanitize=address -g3

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

norm:
	@printf "\n${GRN}##########${YEL} NORMINETTE ${GRN}##########${NOCOL}\n"
	@printf "\n${GRN}LIBFT:${BLU}\n\n"
	@norminette $(LFT_DIR)
	@printf "\n${GRN}FDF:${BLU}\n\n"
	@norminette $(INC_PATH)
	@norminette $(SRC_PATH)
	@printf "${NOCOL}"

.PHONY: all libft+/libft.a clean fclean re norm