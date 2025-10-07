#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), _brain(new Brain())
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
		_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {

    std::cout << GRAY 
			  << "Copy assignment of Dog operator called"
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

Dog::~Dog()
{
	delete _brain;
	std::cout << GRAY
			  << "Dog destructor called!"
			  << RESET
			  << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << GREEN
			  << "Bark Bark!"
			  << RESET
			  << std::endl;
}

Brain* Dog::getBrain() const {
    return _brain;
}
