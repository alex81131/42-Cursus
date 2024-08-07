# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 14:58:30 by kyeh              #+#    #+#              #
#    Updated: 2024/07/10 16:40:36 by kyeh             ###   ########.fr        #
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
NAME	= minishell

# Compiler and flags
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -O3 -fsanitize=address -g3
#-O3: prioritize code optimization for speed at the expense of code size

# Source files
SRC_PARSING	=	$(addprefix parsing/, \
		analyzer.c		fill_cmd.c			fill_str_with_stars.c \
		join_quotes.c	parsing.c			parsing_allocator.c \
		quote_error.c	separator_counter.c	set_redirection.c)
SRC_EXEC	=	$(addprefix exec/, \
		builtin.c	builtin_cd.c	builtin_export.c \
		exec_cmd.c	signal.c)
SRC_VAR		=	$(addprefix var/, \
		env.c)
SRC_REDIR	=	$(addprefix redirection/, \
		redirection.c	left_redirection.c	right_redirection.c \
		lonely_command.c)
SRC_DISPLAY	=	$(addprefix display/, \
		dispay.c)
SRC_UTILS	=	$(addprefix utils/, \
		ft_exit.c)
SRC_FILES	=	main.c $(SRC_PARSING) $(SRC_EXEC) $(SRC_VAR) $(SRC_REDIR) $(SRC_DISPLAY) $(SRC_UTILS)
SRC_PATH	=	src/
SRC			=	$(addprefix $(SRC_PATH), $(SRC_FILES))

HEADER		=	include/

# Object files
OBJ_FILES	=	$(SRC_FILES:%.c=%.o)
OBJ_PATH	=	obj/
OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_FILES))

RM		=	rm -rf

LIBFT	=	libft+/libft.a
#######################################################

$(NAME): $(OBJ)
	@gcc $(CFLAGS) $^ $(LIBFT) -o  $@
	@printf "	\033[2K\r$(DARK_BLUE)minishell\t: $(LIGHT_GREEN)Updated\n\033[0m"

all: $(OBJ_PATH) $(LIBFT) $(NAME) $(HEADER)
	@:

e:	exec
exec:
	@$(MAKE) all
	@./minishell

clfd:
	@rm -f bli blo blu ble cat ls env a b c aa bb pouet toto make 2>/dev/null

$(LIBFT): libft+/include/libft.h
	@$(MAKE) -C libft/
libft+/include/libft.h:
	@git submodule update --ini --recursive

$(OBJ_PATH):
	@mkdir -p obj/ 2> /dev/null
	@mkdir -p obj/parsing 2> /dev/null
	@mkdir -p obj/exec 2> /dev/null
	@mkdir -p obj/var 2> /dev/null
	@mkdir -p obj/display 2> /dev/null
	@mkdir -p obj/redirection 2> /dev/null
	@mkdir -p obj/utils 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER)/minishell.h Makefile
	@printf "\033[2K\r$(LIGHT_RED)Compiling...	\033[37m$<\033[36m \033[0m"
	@gcc $(CFLAGS) -I $(HEADER) -I libft+/include -c $< -o $@

clean:
	@printf "\33[2K\r$(LIGHT_RED)Deleting minishell srcs/	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting minishell srcs/.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting minishell srcs/..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting minishell srcs/...	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting minishell srcs/	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting minishell srcs/.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting minishell srcs/..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Deleting minishell srcs/...	\033[37m"
	@sleep 0.1
	@${RM} ${OBJ_PATH} cube3D.dSYM
	@printf "\33[2K\r$(LIGHT_RED)Deleted successfully!\n\033[0m"

fclean: clean
	$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@make -C libft+/ re
	@$(MAKE) all

norm:
	@printf "\n${GREEN}##########${YELLOW} NORMINETTE ${GREEN}##########${NOCOLOR}\n"
	@printf "\n${GREEN}Minishell:${BLUE}\n\n"
	@norminette $(SRC_PATH) $(HEADER)
	@printf "${NOCOLOR}"
full_norm:
	@printf "\n${GREEN}##########${YELLOW} NORMINETTE ${GREEN}##########${NOCOLOR}\n"
	@printf "\n${GREEN}LIBFT:${BLUE}\n\n"
	@norminette libft+
	@printf "\n${GREEN}Minishell:${BLUE}\n\n"
	@norminette $(SRC_PATH)
	@printf "${NOCOLOR}"

normed:
	@norminette $(SRC_PATH) $(HEADER)
	@$(MAKE) continue
	@echo ""
	@git add .
	@git commit -m "normed" 1>/dev/null
	@printf "\33[2K\r$(YELLOW)Push on repositories ?\n\033[0m"
	@$(MAKE) continue
	@echo ""
	@$(MAKE) push

push:
	@printf "\33[2K\r$(LIGHT_RED)Pushing 	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Pushing .	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Pushing ..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Pushing ...	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Pushing 	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Pushing .	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Pushing ..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r$(LIGHT_RED)Pushing ...	\033[37m"
	@sleep 0.1
	@git push origin `git symbolic-ref --short HEAD`
	@printf "\33[2K\r$(FLASH_GREEN)Pushed successfully on vogsphere !\n\033[0m"

update:
	@git request-pull HEAD https://github.com/alex81131/Minishell.git master

.PHONY: all libft+/libft.a clean fclean re norm