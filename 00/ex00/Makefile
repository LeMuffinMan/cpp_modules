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
CXX 						= c++
CXX_FLAGS 			= -Wall -Wextra -Werror -std=c++98 

# Binary name
NAME 						= megaphone

# Sources and objects
SRCS 						= megaphone.cpp
OBJ_DIR 				= .objs
OBJS 						= $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))
DEPS 						= $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.d))

# Valgrind 
VG 							= valgrind 
VGFLAGS					= --leak-check=full --show-leak-kinds=all \
				   				--track-origins=yes --trace-children=yes

all: $(NAME)

$(NAME): $(OBJS) Makefile 
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp Makefile $(OBJ_DIR)
	$(CXX) $(CXX_FLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEPS)

clean: 
	rm -rf $(OBJ_DIR)

fclean: clean 
	rm -f $(NAME)

re: fclean all

run: all 
	./$(NAME) this_is_a_test_string

test: all 
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(NAME)

vg: 
	$(VG) $(VGFLAGS) ./$(NAME) this " " is " """ a " "test" " string
	$(VG) $(VGFLAGS) ./$(NAME) "shhhhh... I think the students are asleep..."
	$(VG) $(VGFLAGS) ./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	$(VG) $(VGFLAGS) ./$(NAME)

.PHONY: all clean fclean re run test vg



