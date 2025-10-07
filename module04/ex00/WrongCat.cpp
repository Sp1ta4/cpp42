#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << GRAY
			  << this->type
			  << " Default constructor called!"
			  << RESET
			  << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
        std::cout << GRAY 
				  << "WrongCat copy constructor called"
				  << RESET
				  << std::endl;
        *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {

    std::cout << GRAY 
			  << "Copy assignment of WrongCat operator called"
			  << RESET
			  << std::endl;
	if (this != &other)
			this->type = other.getType();
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << GRAY
			  << "WrongCat destructor called!"
			  << RESET
			  << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << GREEN
			  << "Meow meow!"
			  << RESET
			  << std::endl;
}