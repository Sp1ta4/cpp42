#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{}

Fixed::Fixed(const int _value)
{
	this->_value = _value * (1 << this->_bite);
}

Fixed::Fixed(const float _value)
{
	this->_value = roundf(_value * (1 << this->_bite));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << this->_bite));
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_bite);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->getRawBits() != other.getRawBits());
}

const Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

const Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}

const Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() * other.getRawBits() >> this->_bite);
	return (result);
}

const Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;

	result.setRawBits((this->getRawBits() << this->_bite) / other.getRawBits());
	return (result);
}

Fixed &Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

const Fixed Fixed::operator++(int)
{
	Fixed temp = *this;

	++(*this);
	return temp;
}

Fixed &Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

const Fixed Fixed::operator--(int)
{
	Fixed temp = *this;

	--(*this);
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
