#include "Zombie.hpp"
#include <sstream>
#include <climits>
#include <cctype>

bool isNumber(const std::string &s)
{
	if (s.empty())
		return (false);
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!std::isdigit(s[i]))
			return (false);
	}
	return (true);
}

int readPositiveInt()
{
	std::string input;
	int value = 0;

	while (true)
	{
		std::cout << "\033[35mNumber of zombies: \033[0m";
		std::cin >> input;

		if (!isNumber(input))
		{
			std::cout << "\033[31mError: only digits allowed!\033[0m" << std::endl;
			continue;
		}

		if (input.size() > 10)
		{
			std::cout << "\033[31mError: number too large!\033[0m" << std::endl;
			continue;
		}

		std::istringstream iss(input);
		iss >> value;

		if (iss.fail() || value <= 0 || value > INT_MAX)
		{
			std::cout << "\033[31mError: invalid number!\033[0m" << std::endl;
			continue;
		}

		break;
	}

	return (value);
}

int main(void)
{
	std::string hordeName;

	std::cout << "\033[35mName for horde: \033[0m";
	std::cin >> hordeName;

	int N = readPositiveInt();

	Zombie *horde = zombieHorde(N, hordeName);

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;
	return 0;
}
