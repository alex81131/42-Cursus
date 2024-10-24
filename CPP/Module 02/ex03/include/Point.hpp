#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	public:
		Point(void);								// Default constructor
		Point(const float x, const float y);		// Parameterized Constructor
		Point(const Point& src);					// Copy constructor
		Point&	operator = (const Point& src);		// Assignment operator
		~Point(void);								// Deconstructor

		// Return a reference to the Fixed object: _x and _y
		const Fixed&	getx(void) const;
		const Fixed&	gety(void) const;

	private:
		const Fixed	_x;
		const Fixed	_y;
};

Fixed			Area(const Point a, const Point b, const Point c);
bool			bsp(Point const a, Point const b, Point const c, Point const point);

#endif

// Class:
// 	A class is like a blueprint or template that defines the structure and behavior of objects.
// Object:
// 	An object is an instance of a class.