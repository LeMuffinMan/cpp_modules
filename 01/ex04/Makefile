# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/02 12:46:25 by oelleaum          #+#    #+#              #
#    Updated: 2025/08/02 13:03:54 by oelleaum         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC_DIR        := src
INC_DIR        := include
OBJ_DIR        := .objs

CXX            := c++
CXX_FLAGS      := -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

NAME    			 := sed

SRCS    			 := src/main.cpp
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
	@echo "Testing sed without argument :"
	@- ./$(NAME)
	@echo
	echo "Hello World" > test
	cat test
	./$(NAME) test ll ch
	cat test.replace
	@echo
	./$(NAME) test ch ll
	cat test.replace
	@echo
	@echo "Testing with non existing file :"
	rm test
	- ./$(NAME) test ll ch
	- cat test.replace

print-%:
	@echo $($(patsubst print-%,%,$@))

vg:
	echo "Hello World" > test
	$(VG) $(VGFLAGS) ./$(NAME) test ll ch
	$(VG) $(VGFLAGS) ./$(NAME) test ch ll
	rm test
	$(VG) $(VGFLAGS) ./$(NAME) test ll ch
	$(VG) $(VGFLAGS) ./$(NAME)

.PHONY: all clean fclean re run test vg

re: fclean all
