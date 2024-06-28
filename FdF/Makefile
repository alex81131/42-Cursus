# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 18:42:47 by kyeh              #+#    #+#              #
#    Updated: 2024/06/28 14:43:30 by kyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
NOCOL=\033[0m
RED=\033[1;31m
YEL=\033[1;33m
ORG=\033[0;33m
GRN=\033[1;32m
DGRAY=\033[1;30m
BLU=\033[1;34m

# Names
NAME	= fdf

# Compiler and flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CCFLAGS = -Wall -Wextra -Werror
#LIBC	= ar rcs

CFLAGS += -D WIN_H=720 -D WIN_W=1280
CCFLAGS += -D WIN_H=1080 -D WIN_W=1920

CFLAGS += -D BUFFER_SIZE=10
CCFLAGS += -D BUFFER_SIZE=500

CFLAGS += -O3
CCFLAGS += -O3
#-O3: prioritize code optimization for speed at the expense of code size

#CFLAGS += -fsanitize=address -g3
#CCFLAGS += -fsanitize=address -g3

# MiniLibX Libraries
LMLX_NAME_MMS = libmlx.dylib
LMLX_NAME_MACOS_SIERRA = libmlx.a
LMLX_NAME_LINUX = libmlx_Linux.a
#L: Library, MLX: MiniLibX
LMLX_DIR_LINUX = lib/mlx_linux
LMLX_DIR_MMS = lib/mlx_mms
LMLX_DIR_MACOS_SIERRA = lib/mlx_macos_sierra
LMLX = $(LMLX_DIR)/$(LMLX_NAME)

CFLAGS += -I ./$(LMLX_DIR)
CCFLAGS += -I ./$(LMLX_DIR)

# Source files
SRC_FILES = \
		main.c		utils.c		error.c \
		mlx_main.c	mlx_hook.c	mlx_utils.c \
		map_utils.c	handle_args.c	controls.c\
		color.c		draw.c		draw_utils.c
SRC = $(addprefix src/, $(SRC_FILES))

# Object files
OBJ_FILES = $(SRC_FILES:%.c=%.o)
OBJ = $(addprefix obj/, $(OBJ_FILES))

# OS check
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CFLAGS += -D LINUX
	LDLIBS = -Llibft+ -lft -L$(LMLX_DIR) -lmlx_Linux
	LDLIBS += -lXext -lX11 -lm -lz
	LMLX_NAME = $(LMLX_NAME_LINUX)
	LMLX_DIR = $(LMLX_DIR_LINUX)
endif
ifeq ($(UNAME_S),Darwin)
	CFLAGS += -D OSX
#	########## SHARED VARS       ##########
	CCFLAGS += -framework OpenGL -framework AppKit
	LDLIBS = -Llibft+ -lft -L$(LMLX_DIR) -lmlx
#	########## mlx_mms           ##########
#	LMLX_NAME = $(LMLX_NAME_MMS)
#	LMLX_DIR = $(LMLX_DIR_MMS)
#	########## mlx_macos_sierra  ##########
	LMLX_NAME = $(LMLX_NAME_MACOS_SIERRA)
	LMLX_DIR = $(LMLX_DIR_MACOS_SIERRA)
endif
LDFLAGS = -L ./

RM		= rm -rf

#######################################################

${NAME}: libft+/libft.a $(LMLX_NAME) $(OBJ)
	gcc $^ -o  $@ $(CCFLAGS) $(LDFLAGS) $(LDLIBS)

all: $(NAME)

$(LMLX_NAME):
	$(MAKE) all -sC $(LMLX_DIR) 2> /dev/null
	cp $(LMLX) $(LMLX_NAME)

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CCFLAGS) -c $< -o $@

libft+/libft.a:
	make -C libft+

clean:
	make clean -C libft+
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft+

re:	fclean all

norm:
	@printf "\n${GRN}##########${YEL} NORMINETTE ${GRN}##########${NOCOL}\n"
	@printf "\n${GRN}LIBFT:${BLU}\n\n"
	@norminette libft+
	@printf "\n${GRN}FDF:${BLU}\n\n"
	@norminette src
	@printf "${NOCOL}"

.PHONY: all libft+/libft.a clean fclean re norm