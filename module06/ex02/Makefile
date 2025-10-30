NAME = Base

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
DEBUGFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -std=c++98

SOURCES =	main.cpp \
			Base.cpp \

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CPPFLAGS) $^ -o $(NAME) -I.

%.o: %.cpp Makefile
	$(CXX) $(CPPFLAGS) -c $< -o $@

debug: CPPFLAGS = $(DEBUGFLAGS)
debug: fclean $(NAME)
	@echo "\033[32mProject compiled in DEBUG mode with AddressSanitizer\033[0m"

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
