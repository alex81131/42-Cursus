#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point& other);
		Point&	operator = (const Point& other);
		~Point(void);

	private:
		const Fixed	_x;
		const Fixed	_y;
};

std::ostream&	operator << (std::ostream& ostream, const Fixed& fp_number);

#endif

// Declare operator<< outside of the class declaration is that operator<< is not inherently part of the Fixed class's functionality.
// 	Instead, it's a function that facilitates interaction between Fixed and std::ostream (like std::cout).

// Overload the insertion («) operator = implement a new functionality on the operator <<
// 	Before overloading, << couldn’t print a fixed-point number assigned by the subject.
// 	By overloading, you define how << should print a custom data type such as "Fixed".
// ie. in main.cpp
// 	Without overloading, "std::cout << a" wouldn’t know how to handle a "Fixed object",
// 	similarly for b, c, and d. Such attemptation would would result in a compilation error.

// <cmath>
// 	roundf