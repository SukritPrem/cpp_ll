NAME = a.out

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =  main.cpp 
HEADERS =  easyfind.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(OBJS): $(HEADERS)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re