CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -MMD -MP
OBJS_DIR = .objs
SRCS = src/ScalarConverter.cpp src/main.cpp
OBJS = $(patsubst src/%.cpp,$(OBJS_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)
VG = valgrind 
VGFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes
NAME = scalar_converter

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

run: all 
	@echo "=== BASIC TESTS ==="
	./$(NAME) 0
	@echo "==========================="
	./$(NAME) 42
	@echo "==========================="
	./$(NAME) -42
	@echo "==========================="
	./$(NAME) 64
	@echo "==========================="
	./$(NAME) 90
	@echo "==========================="
	./$(NAME) 127
	@echo "==========================="
	./$(NAME) 128
	@echo "==========================="
	./$(NAME) -1
	@echo "==========================="
	./$(NAME) 2147483647
	@echo "==========================="
	./$(NAME) -2147483648
	@echo "==========================="
	
	@echo "=== CHAR TESTS ==="
	./$(NAME) 'a'
	@echo "==========================="
	./$(NAME) 'A'
	@echo "==========================="
	./$(NAME) 'z'
	@echo "==========================="
	./$(NAME) 'Z'
	@echo "==========================="
	./$(NAME) '0'
	@echo "==========================="
	./$(NAME) ' '
	@echo "==========================="
	./$(NAME) '~'
	@echo "==========================="
	
	@echo "=== FLOAT TESTS ==="
	./$(NAME) 0.0f
	@echo "==========================="
	./$(NAME) -4.2f
	@echo "==========================="
	./$(NAME) 4.2f
	@echo "==========================="
	./$(NAME) 42.0f
	@echo "==========================="
	./$(NAME) -42.0f
	@echo "==========================="
	
	@echo "=== DOUBLE TESTS ==="
	./$(NAME) 0.0
	@echo "==========================="
	./$(NAME) -4.2
	@echo "==========================="
	./$(NAME) 4.2
	@echo "==========================="
	./$(NAME) 42.0
	@echo "==========================="
	./$(NAME) -42.0
	@echo "==========================="
	
	@echo "=== SPECIAL VALUES TESTS ==="
	./$(NAME) nan
	@echo "==========================="
	./$(NAME) nanf
	@echo "==========================="
	./$(NAME) +inf
	@echo "==========================="
	./$(NAME) +inff
	@echo "==========================="
	./$(NAME) -inf
	@echo "==========================="
	./$(NAME) -inff
	@echo "==========================="
	
	@echo "=== EDGE CASES TESTS ==="
	-./$(NAME) ""
	@echo "==========================="
	-./$(NAME) "hello"
	@echo "==========================="
	-./$(NAME) "42.42.42"
	@echo "==========================="
	-./$(NAME) "42f"
	@echo "==========================="
	-./$(NAME) "123456789012345678901234567890"
	@echo "==========================="
	-./$(NAME) "123.456f.789"
	@echo "==========================="
	-./$(NAME) "+"
	@echo "==========================="
	-./$(NAME) "-"
	@echo "==========================="
	-./$(NAME) "."
	@echo "==========================="
	-./$(NAME) "f"
	@echo "==========================="
	-./$(NAME) "123abc"
	@echo "==========================="
	
.PHONY: all clean fclean re run
