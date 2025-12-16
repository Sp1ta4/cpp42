#pragma once

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <sstream>
# include <string.h>
# include <cstdlib>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

typedef std::map<std::string, double> Database;

class BitcoinExchange
{
	private:
		enum Months
		{
			January = 1,
			February,
			March,
			April,
			May,
			June,
			Jule,
			August,
			September,
			October,
			November,
			December
		};
	
		std::string	_input;
		Database	_database;
		bool 		_isValidDate(const std::string &date);
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &filename);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void exchange();
};
