CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -MMD -MP
OBJS_DIR = .objs
SRCS = $(wildcard .)
OBJS = $(patsubst src/%.cpp,$(OBJS_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)
VG = valgrind 
VGFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes
NAME = AMateria

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
	./$(NAME)

vg: 
	$(VG) $(VGFLAGS) ./$(NAME) 

.PHONY: all clean fclean re run vg