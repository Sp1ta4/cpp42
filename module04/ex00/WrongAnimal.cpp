#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("UNKNOWN")
{
	std::cout << GRAY
			  << this->type
			  << " Default constructor called!"
			  << RESET
			  << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) {
	std::cout << GRAY
			  << "WrongAnimal argument constructor called"
			  << RESET
			  << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << GRAY
			  << this->type
			  << " WrongAnimal copy constructor called"
			  << RESET
			  << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << GRAY
			  << this->type
			  << " Copy assignment of WrongAnimal operator called"
			  << RESET
			  << std::endl;
	if (this != &other)
			this->type = other.getType();
	return *this;
}

std::string	WrongAnimal::getType() const {
	return (this->type);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << GRAY
			  << "WrongAnimal destructor called!"
			  << RESET
			  << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << GREEN
			  << this->type
			  << " make sound was called"
			  << RESET
			  << std::endl;
}