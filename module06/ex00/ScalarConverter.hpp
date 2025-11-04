#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#	include <iomanip>
#	include <iostream>
#	include <cmath>
#	include <cstring>
#	include <cstdlib>
#	include <sstream>
#	include <stdint.h>
# 	include "colors.hpp"

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		virtual ~ScalarConverter();
	public:
		static void convert(const std::string &literal);
		
};

int validation(const std::string &av);

#endif