SRCS	= ./display.c
OBJS	= ${SRCS:.c=.o}
NAME	= ft_display_file
CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror
## "binary" refers to an executable file that contains machine-readable instructions.
## In this case, "ft_display_file" is the name of the binary file
## that will be created by compiling the code. Once compiled,
## this binary file can be executed to run the program.
.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} 

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re .c.o