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

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator = (const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_raw = other._raw;
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

/*_______________comparison operator overloads_______________*/
bool	Fixed::operator > (const Fixed& other) const
{
	return this->_raw > other._raw;
}
// reusing the > operator:
bool	Fixed::operator < (const Fixed& other) const
{
	return other > *this;
}
bool	Fixed::operator >= (const Fixed& other) const
{
	return !(other > *this);
}
bool	Fixed::operator <= (const Fixed& other) const
{
	return !(*this > other);
}
bool	Fixed::operator == (const Fixed& other) const
{
	return this->_raw == other._raw;
}
bool	Fixed::operator != (const Fixed& other) const
{
	return this->_raw != other._raw;
}

/*_______________arithmetic operator overloads_______________*/
Fixed	Fixed::operator + (const Fixed& other) const
{
	Fixed	res = *this;

	res._raw += other._raw;
	return res;
}

Fixed	Fixed::operator - (const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator * (const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator / (const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

/*_______________increment and decrement overlaods_______________*/
Fixed&	Fixed::operator ++ (void)
{
	this->_raw += 1;
	return *this;
}

Fixed&	Fixed::operator -- (void)
{
	--(this->_raw);
	return *this;
}

Fixed	Fixed::operator ++ (int)
{
	Fixed	temp = *this;

	++*this;
	return temp;
}

Fixed	Fixed::operator -- (int)
{
	Fixed	prev(*this);

	--*this;
	return prev;
}

/*_______________min max functions_______________*/
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}


const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
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