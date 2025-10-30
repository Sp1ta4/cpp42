#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << "ScalarConverter default constructor called" << RESET << std::endl; 
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	if (this != &other)
	{

	}
	return *this;
}



ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "ScalarConverter destructor called" << RESET << std::endl; 
}

