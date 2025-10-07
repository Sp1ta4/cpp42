#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"), _brain(new Brain())
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
		_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {

    std::cout << GRAY 
			  << "Copy assignment of Cat operator called"
			  << RESET
			  << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << GRAY
			  << "Cat destructor called!"
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

Brain* Cat::getBrain() const {
    return _brain;
}
