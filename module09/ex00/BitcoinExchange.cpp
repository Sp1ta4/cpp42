#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>


static bool isLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static bool isValidFloat(const std::string &str)
{
	std::stringstream ss(str);
	double x;

	ss >> x;

	return ss.eof() && !ss.fail();
}

static bool isValidDateFormat(std::string &date)
{
	if (date.length() != 10)
	{
		return false;
	}

	for (size_t i = 0; i < date.size(); ++i)
	{
		if ((i == 4 || i == 7))
		{
			if (date[i] != '-')
				return false;
		}
		else
		{
			if (!isdigit(date[i]))
				return false;
		}
	}

	return true;
}

static double stringToDouble(const std::string &str)
{
	std::stringstream ss(str);
	double result;

	ss >> result;

	if (ss.fail() || !ss.eof())
	{
		return -1;
	}

	return result;
}


BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const std::string &filename) : _input(filename)
{
	std::ifstream datafile("data.csv");
	if (!datafile)
	{
		exit(1 && (std::cout << "Error: could not find data.csv" << std::endl));
	}

	std::string header;
	if (!getline(datafile, header))
	{
		exit(1 && (std::cout << "Error: data.csv or file is empty" << std::endl));
	}

	std::string line;
	while (getline(datafile, line))
	{
		size_t delim_position = line.find(',');
		if (delim_position == std::string::npos)
		{
			exit(1 && (std::cout << "Error: invalid data format in data.csv." << std::endl));
		}

		std::string date = line.substr(0, delim_position);
		if (!isValidDateFormat(date) || !_isValidDate(date))
		{
			exit(1 && (std::cout << "Error: not valid date: " << line << std::endl));
		}

		std::string price_value = line.substr(delim_position + 1);
		if (!isValidFloat(price_value))
		{
			exit(1 && (std::cout << "Error: not valid price: " << price_value << std::endl));
		}

		double price = stringToDouble(price_value);
		if (price < 0)
		{
			exit(1 && (std::cout << "Error: price can't be negative: " << price_value << std::endl));
		}

		this->_database[date] = price;
	}
	datafile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _input(other._input), _database(other._database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_input = other._input;
		this->_database = other._database;
	}

	return (*this);
}

BitcoinExchange::~BitcoinExchange() {};

bool BitcoinExchange::_isValidDate(const std::string &date)
{
	int year  = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day   = std::atoi(date.substr(8, 2).c_str());

	if (year <= 0 || month < 1 || month > 12 || day < 1)
		return false;

	switch (month)
	{
		case February:
			return day <= (isLeapYear(year) ? 29 : 28);
		case April:
		case June:
		case September:
		case November:
			return day <= 30;
		default:
			return day <= 31;
	}
}


void BitcoinExchange::exchange()
{
	std::ifstream infile(this->_input.c_str());
	if (!infile.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	if (!std::getline(infile, line))
	{
		std::cout << "Error: input file is empty." << std::endl;
		return;
	}

	if (line != "date | value")
	{
		std::cout << "Error: invalid header." << std::endl;
		return;
	}

	while (std::getline(infile, line))
	{
		if (line.empty())
			continue;

		size_t pipe = line.find(" | ");
		if (pipe == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pipe);
		std::string valueStr = line.substr(pipe + 3);

		if (!isValidDateFormat(date) || !_isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		double value;
		try
		{
			value = stringToDouble(valueStr);
		}
		catch (...)
		{
			std::cout << "Error: bad input => " << valueStr << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		Database::iterator it = this->_database.lower_bound(date);

		if (it == this->_database.begin() && it->first != date)
		{
			std::cout << "Error: no data for date => " << date << std::endl;
			continue;
		}

		if (it == this->_database.end() || it->first != date)
			--it;

		double result = value * it->second;

		std::cout << date << " => " << value << " = " << result << std::endl;
	}

	infile.close();
}
