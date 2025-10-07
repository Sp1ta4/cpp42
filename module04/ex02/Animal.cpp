#include "Animal.hpp"

Animal::Animal(void) : type("UNKNOWN")
{
	std::cout << GRAY
			  << this->type
			  << " Default constructor called!"
			  << RESET
			  << std::endl;
}

Animal::Animal(const std::string& type) {
	std::cout << GRAY
			  << "Animal argument constructor called"
			  << RESET
			  << std::endl;
	this->type = type;
}

Animal::Animal(const Animal& other) {
	std::cout << GRAY
			  << "Animal copy constructor called"
			  << RESET
			  << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << GRAY
			  << "Copy assignment of Animal operator called"
			  << RESET
			  << std::endl;
	if (this != &other)
			this->type = other.getType();
	return *this;
}

std::string	Animal::getType() const {
	return (this->type);
}

Animal::~Animal()
{
	std::cout << GRAY
			  << "Animal Destructor called!"
			  << RESET
			  << std::endl;
}
