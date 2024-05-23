# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/11 15:15:44 by ndahib            #+#    #+#              #
#    Updated: 2024/05/23 11:11:52 by ndahib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= webserv
ROOT		:= .

# ******Commands************************************************************* #

RM			:= rm -rf
CPP			:= c++
CPPFLAGS	:= -Wall -Wextra -Werror -std=c++98
INCLUDE		:= $(addprefix -I , $(SRC_DIR/*))


# ******Directories********************************************************** #
SRC_DIR		:= src
OBJ_DIR		:= build
# ******Files**************************************************************** #

AUXFILES	:= Readme.txt Makefile webserv.yml
SRCFILES	:= $(shell find $(ROOT) -type f -name "*.cpp")
HDRFILES	:= $(shell find $(ROOT) -type f -name "*.hpp")
OBJFILES	:= $(patsubst %.cpp,%.o,$(SRCFILES))


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
	echo $(INCLUDE)

Shell_env :
	$(info $(NAME) $(origin NAME))
	$(info $(shell printenv | grep NAME))
	printf "$(GREEN) Testing ..." $<

$(NAME): $(OBJFILES)
	$(CPP) $(CFLAGS) $(INCLUDE) $(OBJFILES) -o $@
	@printf "$(GREEN) [OK]	$(YELLOW)$@ is created !! $(DEF)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp 
	mkdir -p $(dir $@)
	$(CPP) $(CFLAGS) $(INCLUDE) -c $< -o $@
	printf "$(GREEN) [OK]	$(PURPLE)Compiling ==> $(DEF)%5s\n" $<

clean:
	@if [ -d $(OBJ_DIR) ]; then\
		$(RM) $(OBJ_DIR);\
		echo "$(GREEN) [OK]  $(RED) Object Files are Cleaned!$(DEF)";\
	fi

fclean: clean
	@if [ -f $(NAME) ]; then\
		$(RM) $(NAME);\
		echo "$(GREEN) [OK]  $(RED) $(NAME) Cleaned!$(DEF)";\
	fi

re:	fclean all

.PHONY: all clean fclean re