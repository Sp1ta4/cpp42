#include "Harl.hpp"

Harl::Harl(void)
{
	return;
}

Harl::~Harl(void)
{
	return;
}

void Harl::warning(void)
{
	std::cout << "\033[33m[ WARNING ]\033[0m" << std::endl;
	std::cout << "\033[33mI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\033[0m" << std::endl
			  << std::endl;
}

void Harl::info(void)
{
	std::cout << "\033[36m[ INFO ]" << std::endl;
	std::cout << "\033[36mI cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\033[0m" << std::endl
			  << std::endl;
}

void Harl::debug(void)
{
	std::cout << "\033[37m[ DEBUG ]" << std::endl;
	std::cout << "\033[37mI think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month.\033[0m" << std::endl
			  << std::endl;
}

void Harl::error(void)
{
	std::cout << "\033[31m[ ERROR ]\033[0m" << std::endl;
	std::cout << "\033[31mThis is unacceptable! I want to speak to the manager now.\033[0m" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcs[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;

	while (level != levels[i] && i < 4)
		i++;
	switch (i)
	{
		case 0:
			(this->*funcs[0])(); // DEBUG
			// fall through
		case 1:
			(this->*funcs[1])(); // INFO
			// fall through
		case 2:
			(this->*funcs[2])(); // WARNING
			// fall through
		case 3:
			(this->*funcs[3])(); // ERROR
			break;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
