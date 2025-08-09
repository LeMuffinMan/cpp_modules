CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++98 -Iinclude -MMD -MP
SRC_DIR = src
OBJS_DIR = .objs
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJS_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

NAME = configparser

all: $(NAME)

$(NAME): $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp Makefile | $(OBJS_DIR)
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