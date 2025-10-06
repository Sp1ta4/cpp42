#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << GRAY
			  << this->type
			  << " Default constructor called!"
			  << RESET
			  << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << GRAY
		  << "Dog copy constructor called"
		  << RESET
		  << std::endl;
        *this = other;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << GRAY
			  << "Copy assignment of Dog operator called!"
			  << RESET
			  << std::endl;
	if (this != &other)
			this->type = other.getType();
	return *this;
}

Dog::~Dog()
{
	std::cout << GRAY
			  << this->type
			  << " Destructor called!"
			  << RESET
			  << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << GREEN
			  << "Bark bark!"
			  << RESET
			  << std::endl;
}