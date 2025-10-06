#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << GRAY
			  << this->type
			  << " Default constructor called!"
			  << RESET
			  << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
        std::cout << GRAY 
				  << "Cat copy constructor called"
				  << RESET
				  << std::endl;
        *this = other;
}

Cat& Cat::operator=(const Cat& other) {

    std::cout << GRAY 
			  << "Copy assignment of Cat operator called"
			  << RESET
			  << std::endl;
	if (this != &other)
			this->type = other.getType();
	return *this;
}

Cat::~Cat()
{
	std::cout << GRAY
			  << this->type
			  << " Destructor called!"
			  << RESET
			  << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << GREEN
			  << "Meow meow!"
			  << RESET
			  << std::endl;
}