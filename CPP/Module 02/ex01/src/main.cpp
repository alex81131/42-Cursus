#include "Fixed.hpp"
#include <iostream>

int main( void ) {

	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

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

// Reflexion pour le passage de int  float de cyferrei :

// int Var = 12;
// [0000 0000] [0000 0000] [0000 0000] [0000 1100] int = 12

// Fixed :
// ------------------Entiere---------        ---Mant-----
// [0000 0000] [0000 0000] [0000 0000] <---> [0000 0000]

// int32_t ---> 32 bits entier
// int24_t ---> 24 bits entier + float8_t --> bits decimaux

// Var to fixed => (Var << _nbBits) <=> (Var << 8) <=> (12 << 8) <=> (12 * 2^8)
// [0000 0000] [0000 0000] [0000 1100] <---> [0000 0000]

// fixed to Var => (Var >> _nbBits) <=> (Var >> 8) <=> (3072 >> 8) <=> (3072 / 2^8)
// [0000 0000] [0000 0000] [0000 0000] <---> [0000 1100]

// float Varbis = 12.852f;
// VarBis to fixed = (VarBis * 2^8) <=> (12.852 * 2^8) <=> 3290.112
// => roundf(3290.112) => 3290

// fixed to float = (3290 / 2^8) ==> 12.852