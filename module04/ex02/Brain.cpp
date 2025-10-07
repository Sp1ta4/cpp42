#include "Brain.hpp"
#include "Animal.hpp"

Brain::Brain(void)
{
	std::cout << GRAY
		  	  << "Brain default constructor called!"
			  << RESET
			  << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Copy constructor of Brain called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Copy assignment of Brain operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << GRAY
		  	  << "Brain destructor called!"
			  << RESET
			  << std::endl;

}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        _ideas[index] = idea;
    else
        std::cout << "Invalid index for idea!" << std::endl;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return _ideas[index];
    return "";
}
