#include "Harl.hpp"

int main(void)
{
	Harl harl;
	std::string name;

	while (1)
	{
		if (std::cin.eof())
			return (1);
		std::cout << "\033[35mInput level --> \033[0m";
		std::getline(std::cin, name);
		harl.complain(name);
	}
	return (0);
}