#include "AMaterial.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria argument constructor called" << std::endl;
}

std::string const &AMateria::getType() const {
	return (this->_type);
}