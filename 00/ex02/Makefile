# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/02 14:57:41 by oelleaum          #+#    #+#              #
#    Updated: 2025/08/02 14:57:51 by oelleaum         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS 				= -Wall -Wextra Werror -std=c++98 -Iinclude -MMD -MP

SRC_DIR 				= src
OBJS_DIR 				= .objs

SRCS = src/Account.cpp src/tests.cpp
OBJS 						= $(patsubst $(SRC_DIR)/%.cpp,$(OBJS_DIR)/%.o,$(SRCS))
DEPS 						= $(OBJS:.o=.d)

VG 							= valgrind 
VGFLAGS					= --leak-check=full --show-leak-kinds=all \
				   				--track-origins=yes --trace-children=yes

NAME = MyDreamJob

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

-include $(DEPS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all 
	./$(NAME)

vg: 
	$(VG) $(VGFLAGS) ./$(NAME) 

.PHONY: all clean fclean re run vg
