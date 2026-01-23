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

test:  all
	./$(NAME) "7" "7" "*" "7" || true
	./$(NAME) "1" "2" "*" "2" "/" "2" "*" "2" "4" "-" "+" || true
	./$(NAME) "(1" "+" "1)" || true
	./$(NAME) "1" || true
	./$(NAME) "1" "2" "3"
	./$(NAME) "-1" "2" "3" || true
	./$(NAME) "1" "2" "-3" || true
	./$(NAME) "1" "2" "2" || true
	./$(NAME) "1" "1" "2" || true
	./$(NAME) "42" || true
	./$(NAME) "9" "8" "7" "6" "5" "4" "3" "2" "1" "0" || true
	./$(NAME) "7" "7" "7" "7" "7" || true
	./$(NAME) "1" "2" "1" "2" "1" "2" || true
	./$(NAME) "100000000000000000000000000000" "2" "3" "4" || true

run: all
	./$(NAME) 3 5 9 7 4
	@echo
	./$(NAME) "1" "3" "2"
	@echo
	./$(NAME) "5" "4" "3" "2" "1"
	@echo
	./$(NAME) "1" "2" "3" "4" "5"
	@echo
	./$(NAME) "100" "50" "25" "75" "125" "175" "150" "200"
	@echo
	./$(NAME) `shuf -i 1000000-1001000 -n 100 | tr "\n" " "`
	@echo
	./$(NAME) `shuf -i 1-1000 -n 500 | tr "\n" " "`
	@echo
	./$(NAME) `seq 100 -1 1 | tr "\n" " "`
	@echo
	./$(NAME) `shuf -i 1-5000 -n 2000 | tr "\n" " "`
	@echo
	./$(NAME) `shuf -i 1-5000 -n 3000 | tr "\n" " "`
	@echo
	./$(NAME) `shuf -i 1-5000 -n 4000 | tr "\n" " "`
	@echo
	./$(NAME) `shuf -i 1-6000 -n 4000 | tr "\n" " "`
	@echo


.PHONY: all clean fclean re test run
