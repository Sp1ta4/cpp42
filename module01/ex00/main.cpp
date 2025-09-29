#include "Zombie.hpp"

int main(void)
{
	std::string stackZombieName;
	std::string heapZombieName;

	std::cout << "\033[35mName for stack zombie: \033[0m";
	std::cin >> stackZombieName;

	randomChump(stackZombieName);

	std::cout << "\033[35mName for heap zombie: \033[0m";
	std::cin >> heapZombieName;

	Zombie *heapZombie = newZombie(heapZombieName);
	heapZombie->announce();
	delete (heapZombie);

	return (0);
}