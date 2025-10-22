#include "AMateria.hpp"

AMateria::AMateria() : _type("undefined") {
	std::cout << "Default constructor of AMateria called" << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type) {
	std::cout << "Constructor of AMateria with parameters called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
	std::cout << "Copy constructor of AMateria called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	std::cout << "Copy assignment of AMateria operator called" << std::endl;
	if (this != &other)
			this->_type = other.getType();
	return *this;
}

void	AMateria::use(ICharacter& target) {
	std::cout << "* AMateria use was called --> " << target.getName() << " *" << std::endl;
}

std::string const &	AMateria::getType() const {
	std::cout << "AMateria getType was called" << std::endl;
	return (this->_type);
}

AMateria::~AMateria() {
	std::cout << "Destructor of AMateria called" << std::endl;
}