#include "BitcoinExchange.hpp"
#include <exception>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED << "Error: invalid numbers of argument" << std::endl;
		std::cout << MAGENTA << "run programm like this \"./btc <filename>\"" << std::endl;
		return (1);
	}
	BitcoinExchange btc(argv[1]);
	try
	{
		btc.exchange();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}