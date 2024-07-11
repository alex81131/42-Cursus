# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 16:32:18 by tclaudel          #+#    #+#              #
#    Updated: 2020/04/22 15:19:16 by coscialp         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #



SRCS_ALLOC		=	$(addprefix alloc/, ft_calloc.c ft_strdup.c ft_strndup.c\
					ft_substr.c)

SRCS_CHAR		=	$(addprefix char/, ft_isalnum.c ft_isalpha.c ft_isascii.c\
					ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c)

SRCS_CONVERT	=	$(addprefix convert/, ft_atoi.c ft_itoa.c ft_itoa_base.c\
					ft_itoa_ll_base.c ft_itoa_u_base.c ft_hash.c)

SRCS_DISPLAY	=	$(addprefix display/, ft_putchar.c ft_putchar_fd.c\
					ft_putendl_fd.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c\
					ft_display_tab.c)

SRCS_FREE		=	$(addprefix free/, ft_strdel.c ft_free_tab.c ft_memdel.c)

SRCS_LIST		=	$(addprefix list/, ft_lstadd_back.c\
					ft_lstadd_front.c ft_lstlast.c\
					ft_lstnew.c ft_lstsize.c )

SRCS_MEM		=	$(addprefix mem/, ft_bzero.c ft_memccpy.c ft_memchr.c\
					ft_memcmp.c ft_memcpy.c ft_memfjoin.c ft_memjoin.c\
					ft_memmove.c ft_memset.c)

SRCS_STR		=	$(addprefix str/, ft_split.c ft_strchr.c ft_strcpy.c\
					ft_strfjoin.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
					ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnlen.c\
					ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strtrim.c ft_strtok.c\
					ft_strcmp.c ft_count_whitespaces.c ft_tablen.c\
					ft_charpos.c ft_charrpos.c ft_clearcharset.c ft_insert.c ft_tabjoin.c\
					ft_char_counter.c)

SRCS_READ		=	$(addprefix read/, ft_get_next_line.c)

SRCS_PRINTF		=	$(addprefix display/ft_printf/, ft_d_converter.c ft_p_converter.c ft_s_converter.c ft_upx_converter.c ft_c_converter.c\
					ft_u_converter.c ft_x_converter.c ft_pourcent_converter.c ft_printf.c ft_is_flag.c ft_is_option.c ft_is_pourcent.c\
					ft_analyser.c ft_set_flags.c ft_set_width.c ft_apply_flags.c ft_apply_convert.c ft_router.c ft_is_in_flags.c\
					ft_itoa_pf.c ft_char_in_string.c ft_dprintf.c ft_printfduq.c)

SRCS_HASH		=	$(addprefix hash/, ft_hashnew.c ft_hashadd_front.c\
					ft_hashadd_back.c ft_hashdel.c ft_hash_display.c ft_hash_free.c\
					ft_hash_search_value.c ft_hashlen.c ft_hash_change_value.c\
					ft_hash_init.c ft_hash_sort.c ft_hash_find.c)

SRCS_NAME			=	$(SRCS_ALLOC) $(SRCS_CHAR) $(SRCS_CONVERT) $(SRCS_DISPLAY) $(SRCS_FREE) $(SRCS_LIST) $(SRCS_MEM) $(SRCS_STR) $(SRCS_READ) $(SRCS_PRINTF) $(SRCS_HASH)

HEADER				=	includes/

SRC_PATH			=	srcs/

SRCS				=	$(addprefix $(SRC_PATH), $(SRCS_NAME))

OBJ_NAME			=	${SRCS_NAME:.c=.o}

OBJ_PATH			=	bin/

OBJ					=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))

NAME				=	libft.a

CC					=	cc

RM					=	rm -rf

FLAG				=	-Wall -Wextra -g3 -Werror

all: $(OBJ_PATH) $(NAME)

$(PULL):
	@git pull origin master

$(NAME): $(OBJ) $(HEADER)
	@ar rcs $(NAME) $(OBJ)
	@printf "	\033[2K\r\033[1;38;5;110mlibft\t\t: \033[0;38;5;121mUpdated\n\033[0m"

$(OBJ_PATH):
	@mkdir -p bin/ 2> /dev/null
	@mkdir -p bin/alloc 2> /dev/null
	@mkdir -p bin/char 2> /dev/null
	@mkdir -p bin/convert 2> /dev/null
	@mkdir -p bin/display 2> /dev/null
	@mkdir -p bin/display/ft_printf 2> /dev/null
	@mkdir -p bin/free 2> /dev/null
	@mkdir -p bin/list 2> /dev/null
	@mkdir -p bin/mem 2> /dev/null
	@mkdir -p bin/str 2> /dev/null
	@mkdir -p bin/read 2> /dev/null
	@mkdir -p bin/hash 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) Makefile
	@printf "\033[2K\r\033[0;31;5;110mCompiling...	\033[37m$<\033[36m \033[0m"
	@gcc $(FLAG) -g3 -I ${HEADER} -c $< -o $@

pull:
	@git pull origin master

norme:
	@norminette $(SRC_PATH) $(HEADER)

clean:
	@printf "\33[2K\r\033[0;31;5;110mDeleting libft srcs/	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r\033[0;31;5;110mDeleting libft srcs/.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r\033[0;31;5;110mDeleting libft srcs/..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r\033[0;31;5;110mDeleting libft srcs/...	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r\033[0;31;5;110mDeleting libft srcs/	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r\033[0;31;5;110mDeleting libft srcs/.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r\033[0;31;5;110mDeleting libft srcs/..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r\033[0;31;5;110mDeleting libft srcs/...	\033[37m"
	@sleep 0.1
	@${RM} ${OBJ_PATH}
	@printf "\33[2K\r\033[0;31;5;110mDeleted successfully!\n\033[0m"

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
