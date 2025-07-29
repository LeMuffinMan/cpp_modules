

NAME    = Harl
SRCS    = main.cpp harl.cpp
OBJS    = $(SRCS:.cpp=.o)
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -Iharl.hpp -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
