CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -MMD -MP
OBJS_DIR = .objs
SRCS = src/main.cpp src/PmergeMe.cpp
OBJS = $(patsubst src/%.cpp,$(OBJS_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)
NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS_DIR)/%.o: src/%.cpp Makefile | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

-include $(DEPS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run:  all
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./$(NAME) "7 7 * 7 -"
	./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	./$(NAME) "(1 + 1)"

.PHONY: all clean fclean re run
