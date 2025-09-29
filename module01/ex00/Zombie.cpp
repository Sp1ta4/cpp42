#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{}

Zombie::~Zombie(void) {
	std::cout << "\033[31mZomibe with name \'\033[0m"
			  << this->_name
			  << "\033[31m\' was deleted!\033[0m"
			  << std::endl;
}

void Zombie::announce(void) {
	std::cout << this->_name
	<< ": BraiiiiiiinnnzzzZ..."
	<< std::endl;
}

std::string Zombie::getName(void) const {
	return (this->_name);
}
