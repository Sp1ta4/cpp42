#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(const float xF, const float yF) : _x(xF), _y(yF)
{}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

float	Point::getX (void) const {
	return (_x.toFloat());
}

float	Point::getY (void) const {
	return (_y.toFloat());
}

Point& Point::operator=(const Point& other) {
	if (this == &other)
		return (*this);
	(Fixed)this->_x = other.getX();
	(Fixed)this->_y = other.getY();
	return (*this);
}

Point::~Point()
{
}
