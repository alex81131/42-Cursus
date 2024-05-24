# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 12:27:51 by kyeh              #+#    #+#              #
#    Updated: 2024/05/16 16:16:52 by kyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCSB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c
OBJS	= ${SRCS:.c=.o}
OBJSB	= ${SRCSB:.c=.o}
NAME	= libft.a
LIBC	= ar rcs
CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

bonus: ${NAME} ${OBJSB}
	${LIBC} ${NAME} ${OBJSB}

clean:
	${RM} ${OBJS} ${OBJSB}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all bonus clean fclean re
# make / make bonus, there's always one file created: libft.a,
# so there's no need to put ${OBJSB} in fclean
# bonus: ${NAME} ${OBJSB}
#		${LIBC} ${NAME} ${OBJSB}
# make bonus → Check ${NAME} Dependency, checking if libft.a exists or needs to be updated
# → Check ${OBJSB} Dependency
# → Execute bonus Target Commands, adding the bonus object files to libft.a
#
# all, clean,... are phony targets, not actual files, used as conditions after make command
# when "make", it builds only the first target in the makefile
#
# -c means compile without linking, and thus renders .o files
# $< represents the dependency to build the target
# $@ represents the target name itself
# -o means output
# $@ specifies that the output should have the same name as the target file
# ar rcs = ar rc + ranlib
