CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -MMD -MP
SRC_DIR = src
OBJS_DIR = .objs
SRCS = src/bsp.cpp src/Fixed.cpp src/main.cpp src/Point.cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJS_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

NAME        := run

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

-include $(DEPS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
