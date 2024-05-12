# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndahib <ndahib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/11 15:15:44 by ndahib            #+#    #+#              #
#    Updated: 2024/05/12 12:11:08 by ndahib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++

# C++FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
C++FLAGS = -Wall -Wextra -Werror
SRC = main.cpp TcpSocket.cpp SocketDirector.cpp

OBJ = $(SRC:.cpp=.o)

NAME = SocketBuilder

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(C++FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
