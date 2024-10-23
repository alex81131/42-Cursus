#include "Fixed.hpp"

Fixed::Fixed(void): _raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i): _raw(i << Fixed::_fraction_bit)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f): _raw(static_cast<int>(roundf(f * (1 << Fixed::_fraction_bit))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed&	Fixed::operator = (const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_raw = src.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	return this->_raw;
}

void	Fixed::setRawBits( int const raw )
{
	this->_raw = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->getRawBits() / (1 << Fixed::_fraction_bit));
}

int	Fixed::toInt( void ) const
{
	return (this->getRawBits() >> Fixed::_fraction_bit);
}

std::ostream&	operator << (std::ostream& ostream, const Fixed& fp_number)
{
	return ostream << fp_number.toFloat();
}

// _raw(static_cast<int>(std::roundf(f * (1 << this->_fraction_bit))))
// 1. Since f is float, it cannot be operated by the << directly, hence (1 << this->_fraction_bit).
// 2. std::roundf:	 Rounds the result to the nearest integer to ensure proper representation.
// 3. For after the std::roundf, it is still a float, needed to be recast into int.

// Fixed point conversion:
// 	uses a left bit shift operation to scale the integer by 2^8 (or 256).
// 	This effectively translates the integer into a format suitable for fixed-point representation,
// 	allowing for fractional calculations while maintaining precision.