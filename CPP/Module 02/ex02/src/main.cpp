#include "Fixed.hpp"
#include <iostream>

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

// In fixed-point arithmetic, a scaling factor like 256 is used to store fractional values
// 	as integers by effectively "fixing" the decimal point.
// 	For example, scaling by 256 means each integer step represents 1/256 in float terms.
// 	Thus, a value of 1 in this format is represented by 256 (1 * 256),
// 	and each increment (or decrement) changes the value by 1/256,
// 	allowing for precise fractional calculations without requiring floating-point numbers.

// In bit-shifting terms, multiplying by 256 can also be done using a left-shift of 8 (<< 8),
// 	and dividing by 256 is a right-shift of 8 (>> 8).
// 	This is a common technique in fixed-point systems because it reduces rounding errors
// 	while keeping calculations efficient.