#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << GREEN << "Serializer default constructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << CYAN << "Serializer copy constructor called" << RESET << std::endl;
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	std::cout << CYAN << "Serializer copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{

	}
	return *this;
}

Serializer::~Serializer()
{
	std::cout << RED << "Serializer destructor called" << RESET << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}