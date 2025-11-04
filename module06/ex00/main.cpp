#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2 && validation(av[1]) == 0)
	{
		ScalarConverter::convert(av[1]);
		return (0);
	}
	std::cout << "only char, int, double, float" << std::endl;
	return (1);
}