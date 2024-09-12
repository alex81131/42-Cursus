# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 14:58:30 by kyeh              #+#    #+#              #
#    Updated: 2024/09/12 15:14:52 by kyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
BLUE		= \033[0;38;5;123m
LIGHT_PINK	= \033[0;38;5;200m
PINK		= \033[0;38;5;198m
DARK_BLUE 	= \033[1;38;5;110m
GREEN		= \033[1;32;111m
LIGHT_GREEN	= \033[0;38;5;121m
LIGHT_RED	= \033[0;31;5;110m
FLASH_GREEN	= \033[33;32m
WHITE_BOLD	= \033[37m
GREY		= \033[3;90m
ORANGE		= \033[3;91m
YELLOW		= \033[0;33m
NOCOLOR		= \033[0m

# Name
NAME	= philo

# Compiler and flags
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# Source files
SRC_FILES	=	main.c utils.c 
SRC_PATH	=	src/
SRC			=	$(addprefix $(SRC_PATH), $(SRC_FILES))

HEADER		=	include/

# Object files
OBJ_FILES	=	$(SRC_FILES:%.c=%.o)
OBJ_PATH	=	obj/
OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_FILES))

RM		=	rm -rf
#######################################################

$(NAME): $(OBJ)
	@gcc $(CFLAGS) $^ -o  $@
	@printf "	\033[2K\r$(DARK_BLUE)philo\t: $(LIGHT_GREEN)Updated\n\033[0m"

all: $(OBJ_PATH) $(NAME) $(HEADER)
	@:

$(OBJ_PATH):
	@mkdir -p obj/ 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER)/philo.h Makefile
	@mkdir -p $(dir $@)
	@printf "\033[2K\r$(LIGHT_RED)Compiling...	\033[37m$<\033[36m \033[0m"
	@gcc $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	@printf "\33[2K\r$(LIGHT_RED)Deleting philo srcs/	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting philo srcs/.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting philo srcs/..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting philo srcs/...	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting philo srcs/	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting philo srcs/.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting philo srcs/..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting philo srcs/...	\033[37m"
	@sleep 0.1
	@${RM} ${OBJ_PATH} cube3D.dSYM
	@printf "\33[2K\r$(LIGHT_RED)Deleted successfully!\n\033[0m"

fclean: clean
	$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
#	@mkdir -p $(dir $@) is used in Makefile rules to ensure that the directory where the object file will be placed exists before attempting to create the object file.
#		-p flag creates any missing parent directories in the specified path:
#			mkdir -p path/to/directory
#			it'll create path and path/to if either of them does not exist.
#		$(dir $@) retrieves the directory path from the target file path:
#			if $@ is obj/main.o, $(dir $@) will be obj/