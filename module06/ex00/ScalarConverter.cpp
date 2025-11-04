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

void char_converter(const std::string &literal)
{
	std::cout << "char " << "'" << static_cast<char>(literal[0]) << "'" << std::endl;
	std::cout << "int " << static_cast<int>(literal[0]) << std::endl;
	std::cout << "float " << std::fixed << std::setprecision(1) << static_cast<float>(literal[0]) << "f" << std::endl;
	std::cout << "double " << std::fixed << std::setprecision(1) << static_cast<double>(literal[0]) << std::endl;
}

void digit_converter(const std::string &literal)
{
	try
	{
		int value = std::atoi(literal.c_str());

		if ((value >= 0 && value <= 31) || value == 127)
			std::cout << "char non-printable" << std::endl;
		else if (value < 0 || value > 128)
			std::cout << "char impossible" << std::endl;
		else
			std::cout << "char " << "'" << static_cast<char>(value) << "'" << std::endl;

		if (literal.length() > 9)
			std::cout << "int impossible" << std::endl;
		else
			std::cout << "int " << value << std::endl;
	}
	catch (const std::exception &exp)
	{
		std::cout << "char impossible" << std::endl;
		std::cout << "int impossible" << std::endl;
	}

	try
	{
		float float_value = std::atof(literal.c_str());

		if (std::floor(float_value) == float_value)
		{
			std::cout << "float " << std::fixed << std::setprecision(1) << float_value << "f" << std::endl;
		}
		else
		{
			std::cout << "float " << float_value << "f" << std::endl;
		}
	}
	catch (const std::exception &exp)
	{
		std::cout << "float impossible" << std::endl;
	}

	try
	{
		double double_value = std::atof(literal.c_str());

		if (std::floor(double_value) == double_value)
		{
			std::cout << "double " << std::fixed << std::setprecision(1) << double_value << std::endl;
		}
		else
		{
			std::cout << "double " << double_value << std::endl;
		}
	}
	catch (const std::exception &exp)
	{
		std::cout << "double impossible" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		char_converter(literal);
		return;
	}

	digit_converter(literal);
}

int validation(const std::string &av)
{
	int i = 0;

	if (av.length() == 1 && !std::isdigit(av[0]))
		return 0;

	while (av[i])
	{
		if (av == "-inff" || av == "+inff" || av == "inff" || av == "inf" || av == "-inf" || av == "+inf")
		{
			std::cout << "char impossible" << std::endl;
			std::cout << "int impossible" << std::endl;

			std::string sign = (av[0] == '-') ? "-" : "";
			std::cout << "float " << sign << "inff" << std::endl;
			std::cout << "double " << sign << "inf" << std::endl;

			exit(0);
		}
		else if (av == "nanf" || av == "nan")
		{
			std::cout << "char impossible" << std::endl;
			std::cout << "int impossible" << std::endl;
			std::cout << "float nanf" << std::endl;
			std::cout << "double nan" << std::endl;
			exit(0);
		}

		if (std::isdigit(av[i]) || av[i] == 'f' || av[i] == '.' || av[i] == '+' || av[i] == '-')
			i++;
		else
			return 1;
	}

	return 0;
}