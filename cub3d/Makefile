# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 12:27:51 by kyeh              #+#    #+#              #
#    Updated: 2024/09/30 16:08:53 by kyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME	= cub3d

# Compiler and flags
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3 #-fsanitize=address

# Source files
SRC_PAR	=	$(addprefix parser/, \
				parser.c			expansion.c			quote.c \
				parser_utils.c		expand_utils.c		heredoc.c)

SRC_FILES	=	main.c $(SRC_PAR)
SRC_PATH	=	src/
SRC			=	$(addprefix $(SRC_PATH), $(SRC_FILES))

HEADER		=	include/

# Object files
OBJ_FILES	=	$(SRC_FILES:%.c=%.o)
OBJ_PATH	=	obj/
OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_FILES))

RM			=	rm -rf

LIBFT_PATH	=	libft/
LIBFT		=	$(addprefix $(LIBFT_PATH), libft.a)

MLX_PATH	= minilibx-linux/
MLXFLAGS	= -L $(MLX_PATH) -lmlx -lXext -lX11 -lXext -lm -lz -Ofast
#######################################################
# Colors
DEFAULT		= \e[0;39m
BLACK		= \e[0;30m
WHITE		= \e[0;97m
WHITE_BOLD	= \e[1;97m
GREY		= \e[0;37m
GREY_DARK	= \e[0;90m
GREY_ITALIC	= \e[3;90m
RED			= \e[0;31m
RED_BOLD	= \e[1;31m
RED_LIGHT	= \e[0;31;110m
RED_FLASH	= \e[0;31;5;110m
PINK		= \e[0;38;5;198m
PINK_BOLD	= \e[1;95m
PINK_LIGHT	= \e[0;38;5;200m
ORANGE_ITALIC= \e[3;91m
YELLOW		= \e[0;33m
YELLOW_BOLD	= \e[1;33m
GREEN		= \e[1;32;111m
GREEN_BOLD	= \e[1;32m
GREEN_LIGHT	= \e[0;38;5;121m
BLUE_BOLD	= \e[1;34m
BLUE_LIGHT	= \e[0;38;5;123m
BLUE_GREY	= \e[1;38;5;110m
SKY			= \e[0;36m
SKY_BOLD	= \e[1;36m
CYAN_LIGHT	= \e[0;96m
NOCOLOR		= \e[0m
RESET_LINE	= \e[2K\r
#######################################################
all: $(MLX) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $^ $(MLX_PATH) -lreadline -o  $@
	@printf "	\033[2K\r$(DARK_BLUE)cub3d\t: $(LIGHT_GREEN)Updated\n\033[0m"

bonus:	$(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

minilibx-linux:
	@if [ ! -d "$@" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $@; \
	else \
		echo "mlx already present in the working directory, aborting clone."; \
	fi

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER)/cub3d.h Makefile
	@mkdir -p $(dir $@)
	@printf "$(RESET_LINE)$(RED_FLASH)Compiling...	$(GREY)$<$(SKY) $(NOCOLOR)"
	@gcc $(CFLAGS) -I $(HEADER) -I libft/include -c $< -o $@

clean: cleanlib cleanmlx
	@printf "$(RESET_LINE)$(RED_FLASH)Deleting cub3d srcs/	$(GREY)"
	@sleep 0.1
	@printf "$(RESET_LINE)$(RED_FLASH)Deleting cub3d srcs/.	$(GREY)"
	@sleep 0.1
	@printf "$(RESET_LINE)$(RED_FLASH)Deleting cub3d srcs/..	$(GREY)"
	@sleep 0.1
	@printf "$(RESET_LINE)$(RED_FLASH)Deleting cub3d srcs/...	$(GREY)"
	@sleep 0.1
	@printf "$(RESET_LINE)$(RED_FLASH)Deleting cub3d srcs/	$(GREY)"
	@sleep 0.1
	@printf "$(RESET_LINE)$(RED_FLASH)Deleting cub3d srcs/.	$(GREY)"
	@sleep 0.1
	@printf "$(RESET_LINE)$(RED_FLASH)Deleting cub3d srcs/..	$(GREY)"
	@sleep 0.1
	@printf "$(RESET_LINE)$(RED_FLASH)Deleting cub3d srcs/...	$(GREY)"
	@sleep 0.1
	@$(RM) $(OBJ_PATH)
	@printf "$(RESET_LINE)$(RED_FLASH)Deleted successfully!\n$(NOCOLOR)"

cleanlib:
	@$(MAKE) -C $(LIBFT_PATH) clean

cleanmlx:
	@$(MAKE) -C $(MLX_PATH) clean

fclean: fcleanlib clean
	@$(RM) $(NAME)

fcleanlib:
	@$(MAKE) -C $(LIBFT_PATH) fclean

re:	fclean all

.PHONY: all bonus minilibx-linux clean cleanlib cleanmlx fclean fcleanlib re
# minilibx-linux:
# 	! -d checks if a directory doesn't exist

# @ suppresses the command being printed to the terminal when it's executed.
# all, clean,... are phony targets, not actual files, used as conditions after make command
# when "make", it builds only the first target in the makefile
#
# -c means compile without linking, and thus renders .o files
# $< represents the dependency to build the target
# $@ represents the target name itself
# -o means output
# $@ specifies that the output should have the same name as the target file
# ar rcs = ar rc + ranlib