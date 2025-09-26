NAME = megaphone

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++ $(CPPFLAGS)

SOURCES =	megaphone.cpp
OBJECS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECS)
	$(CPP) $^ -o $(NAME) -I.

%.o: %.cpp Makefile
	$(CPP) -c $< -o $@

clean:
	rm -rf $(OBJECS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re