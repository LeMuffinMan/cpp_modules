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

SRC_DIR        := src
INC_DIR        := include
OBJ_DIR        := .objs

CXX            := c++
CXX_FLAGS      := -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

NAME           := zombies

SRCS           := $(wildcard $(SRC_DIR)/*.cpp)
OBJS           := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS           := $(OBJS:.o=.d)

VG             := valgrind
VGFLAGS        := --leak-check=full --show-leak-kinds=all \
                  --track-origins=yes --trace-children=yes

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
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
	./$(NAME)

test: all
	./$(NAME)

vg:
	$(VG) $(VGFLAGS) ./$(NAME)

.PHONY: all clean fclean re run test vg

