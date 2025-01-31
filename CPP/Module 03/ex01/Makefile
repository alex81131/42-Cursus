# Name
NAME	= Serena

# Compiler and flags
CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Source files
SRC_FILES	=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp
SRC_PATH	=	src/
SRC			=	$(addprefix $(SRC_PATH), $(SRC_FILES))

# Headers
H_FILES		=	ClapTrap.hpp ScavTrap.hpp
H_PATH		=	include/
HEADER		=	$(addprefix $(H_PATH), $(H_FILES))

# Object files
OBJ_FILES	=	$(SRC_FILES:%.cpp=%.o)
OBJ_PATH	=	obj/
OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_FILES))

RM			=	rm -rf
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
all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $^ -o  $@
	@printf "	$(RESET_LINE)$(BLUE_LIGHT)Serena\t: $(GREEN_LIGHT)Updated\n$(NOCOLOR)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp $(HEADER) Makefile
	@mkdir -p $(dir $@)
	@printf "$(RESET_LINE)$(RED_FLASH)Compiling...	$(GREY)$<$(SKY)$(NOCOLOR)"
	@$(CXX) $(CXXFLAGS) -I $(H_PATH) -c $< -o $@

clean:
	@printf "$(RESET_LINE)$(RED_FLASH)Deleting Serena src/	$(GREY)"
	@sleep 0.1
	@printf "$(RESET_LINE)$(RED_FLASH)Deleting Serena src/.	$(GREY)"
	@sleep 0.1
	@printf "$(RESET_LINE)$(RED_FLASH)Deleting Serena src/..	$(GREY)"
	@sleep 0.1
	@printf "$(RESET_LINE)$(RED_FLASH)Deleting Serena src/...	$(GREY)"
	@sleep 0.1
	@printf "$(RESET_LINE)$(RED_FLASH)Deleting Serena src/	$(GREY)"
	@sleep 0.1
	@printf "$(RESET_LINE)$(RED_FLASH)Deleting Serena src/.	$(GREY)"
	@sleep 0.1
	@printf "$(RESET_LINE)$(RED_FLASH)Deleting Serena src/..	$(GREY)"
	@sleep 0.1
	@printf "$(RESET_LINE)$(RED_FLASH)Deleting Serena src/...	$(GREY)"
	@sleep 0.1
	@$(RM) $(OBJ_PATH)
	@printf "$(RESET_LINE)$(RED_FLASH)Deleted successfully!\n$(NOCOLOR)"

fclean: clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
# @ suppresses the command being printed to the terminal when it's executed.
# all, clean,... are phony targets, not actual files, used as conditions after make command
# when "make", it builds only the first target in the makefile
#
# $< represents the dependency to build the target
# $@ represents the target name itself
# -o means output
# $@ specifies that the output should have the same name as the target file