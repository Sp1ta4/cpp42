#include <iostream>
#include "iter.hpp"
#include <stdlib.h>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

std::string colors[6] = {
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN
};

template <typename T>
void printmyline(const T &a)
{
	std::cout << colors[rand() % 6] << a << RESET << std::endl;
}

int main(void)
{
	int array[] = {1, 2, 3, 4, 14, 6, 6, 6};
	std::cout << "Non-const array:" << std::endl;
	iter(array, 8, printmyline);

	const int stepanPartamian[] = {818, 244, 24, 68};
	std::cout << "\nConst array:" << std::endl;
	iter(stepanPartamian, 4, printmyline);

	return 0;
}