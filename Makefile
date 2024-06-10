# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/11 15:15:44 by ndahib            #+#    #+#              #
#    Updated: 2024/06/08 15:52:38 by ndahib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= webserv

# ******Directories********************************************************** #
SRC_DIR		:= srcs
OBJ_DIR		:= build
INC_DIR		:= $(shell find $(SRC_DIR) -type d)
# ******Files**************************************************************** #

AUXFILES	:= Server.log
# SRCFILES	:= $(shell find $(SRC_DIR/*) -type -f -name "*.cpp")
SRCFILES    := $(shell find $(SRC_DIR) -type f -name "*.cpp")
HDRFILES	:= $(shell find $(SRC_DIR) -type f -name "*.hpp")
OBJFILES	:= $(patsubst $(SRC_DIR/*)/%.cpp,$(OBJ_DIR)/%.o,$(SRCFILES))


# ******Commands************************************************************* #

RM			:= rm -rf
CPP			:= c++
CPPFLAGS	:= -std=c++11 -fsanitize=address
INCLUDE		:= $(addprefix -I , $(INC_DIR))
YAML_CPP_INCLUDE := -I/Users/ndahib/.brew/Cellar/yaml-cpp/0.8.0/include
YAML_CPP_LIB := -L/Users/ndahib/.brew/Cellar/yaml-cpp/0.8.0/lib -lyaml-cpp

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
	$(CPP) $(CPPFLAGS) $(INCLUDE) $(YAML_CPP_INCLUDE) $^ $(YAML_CPP_LIB) -o $@
	@touch Server.log
	@printf "$(GREEN) [OK]	$(YELLOW) Our Srbaay  is created !! $(DEF)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDRFILES)
	mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) $(INCLUDE) $(YAML_CPP_INCLUDE) $^ $(YAML_CPP_LIB) -c $< -o $@
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