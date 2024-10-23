#include "Point.hpp"

Point::Point(void): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

// Copy constructor: a duplicate instance of the existing object
Point::Point(const Point& src):_x(src._x), _y(src._y) {}

Point&	Point::operator = (const Point& src)
{
	// if (this != &src)
	// {
	// 	this->_x = src._x;
	// 	this->_y = src._y;
	// }
	// Since "this->_x" and _y are const and thus cannot be assigned,
	// therefore this overload is by its nature, flawed.
	if (this == &src)
		return *this;
	return *this;
}

Point::~Point(void){}

const Fixed&	Point::getx(void) const
{
	return this->_x;
}
const Fixed&	Point::gety(void) const
{
	return this->_y;
}