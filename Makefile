# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/11 15:15:44 by ndahib            #+#    #+#              #
#    Updated: 2024/05/28 08:47:07 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= webserv

# ******Directories********************************************************** #
SRC_DIR		:= srcs
OBJ_DIR		:= build
INC_DIR		:= $(shell find $(SRC_DIR) -type d)
# ******Files**************************************************************** #

AUXFILES	:= Server.log
SRCFILES	:= $(shell find $(SRC_DIR/*) -type f -name "*.cpp")
HDRFILES	:= $(shell find $(SRC_DIR/*) -type f -name "*.hpp")
OBJFILES	:= $(patsubst $(SRC_DIR/*)/%.cpp,$(OBJ_DIR)/%.o,$(SRCFILES))


# ******Commands************************************************************* #

RM			:= rm -rf
CPP			:= c++
CPPFLAGS	:= -Wall -Wextra -Werror -g -fsanitize=address,leak
INCLUDE		:= $(addprefix -I , $(INC_DIR))

# ******Colors*************************************************************** #
DEF			:= \033[3;39m
GRAY		:= \033[3;90m
PINK		:= \033[3;38;5;199m
RED			:= \033[3;91m
GREEN		:= \033[3;32m
CYAN		:= \033[3;96m
PURPLE		:= \033[3;35m
YELLOW		:= \033[3;93m

# ******Rules**************************************************************** #
all: $(NAME)

$(NAME): $(OBJFILES)
	$(CPP) $(CPPFLAGS) $(INCLUDE) $(OBJFILES) -o $@
	@touch Server.log
	@printf "$(GREEN) [OK]	$(YELLOW) Our Srbaay  is created !! $(DEF)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDRFILES)
	mkdir -p $(dir $@)
	$(CPP) $(CFLAGS) $(INCLUDE) -c $< -o $@
	printf "$(GREEN) [OK]	$(PURPLE)Compiling ==> $(DEF)%5s\n" $<

clean:
	@if [ -d $(OBJ_DIR) ]; then\
		$(RM) $(OBJ_DIR);\
		$(RM) $(AUXFILES);\
		echo "$(GREEN) [OK]  $(RED) Object Files are Cleaned!$(DEF)";\
	fi

fclean: clean
	@if [ -f $(NAME) ]; then\
		$(RM) $(NAME);\
		$(RM) $(AUXFILES);\
		echo "$(GREEN) [OK]  $(RED) $(NAME) Cleaned!$(DEF)";\
	fi

re:	fclean all

.PHONY: all clean fclean re