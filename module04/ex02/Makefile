NAME =  Brain

HEADERS = Animal.hpp Dog.hpp Cat.hpp Brain.hpp

SRCS =  main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		Brain.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS) Makefile
		$(CXX) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re