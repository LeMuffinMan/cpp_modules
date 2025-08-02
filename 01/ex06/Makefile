# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/02 17:31:22 by oelleaum          #+#    #+#              #
#    Updated: 2025/08/02 18:56:12 by oelleaum         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC_DIR        := src
INC_DIR        := include
OBJ_DIR        := .objs

CXX            := c++
CXX_FLAGS      := -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

NAME    			:= harlFilter

SRCS    			:= src/main.cpp src/harl.cpp
OBJS           := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS           := $(OBJS:.o=.d)

VG             := valgrind
VGFLAGS        := --leak-check=full --show-leak-kinds=all \
                  --track-origins=yes --trace-children=yes

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp Makefile | $(OBJ_DIR)
	$(CXX) $(CXX_FLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf *.replace

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

test: all
	./$(NAME) "DEBUG"
	@echo
	@echo "========================"
	@echo
	./$(NAME) "INFO"
	@echo
	@echo "========================"
	@echo
	./$(NAME) "WARNING"
	@echo
	@echo "========================"
	@echo
	./$(NAME) "ERROR"

vg: all
	$(VG) $(VGFLAGS) ./$(NAME) "DEBUG"
	@echo
	@echo "========================"
	@echo
	$(VG) $(VGFLAGS) ./$(NAME) "INFO"
	@echo
	@echo "========================"
	@echo
	$(VG) $(VGFLAGS) ./$(NAME) "WARNING"
	@echo
	@echo "========================"
	@echo
	$(VG) $(VGFLAGS) ./$(NAME) "ERROR"

.PHONY: all clean fclean re run test vg
