# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 16:07:27 by oelleaum          #+#    #+#              #
#    Updated: 2025/07/24 16:16:37 by oelleaum         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Compile and flags
CXX 			:= c++
CXX_FLAGS 		:= -Wall -Wextra -Werror -std=c++98 

# Binary name
NAME 			:= phonebook

# Sources headers and objects
SRCS := main.cpp PhoneBook.cpp Contact.cpp
INC := PhoneBook.hpp Contact.hpp
OBJ_DIR 		:= .objs
OBJS 			:= $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))
DEPS 			:= $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.d))

# Valgrind 
VG 				:= valgrind 
VGFLAGS			:= --leak-check=full --show-leak-kinds=all \
				   --track-origins=yes --trace-children=yes

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXX_FLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEPS)

clean: 
	rm -rf $(OBJ_DIR)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re



