#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& other);
		Fixed&	operator = (const Fixed& other);
		~Fixed(void);

		/*    6 comparison operators    */
		bool	operator > (const Fixed& other) const;
		bool	operator < (const Fixed& other) const;
		bool	operator >= (const Fixed& other) const;
		bool	operator <= (const Fixed& other) const;
		bool	operator == (const Fixed& other) const;
		bool	operator != (const Fixed& other) const;
		/*    4 arithmetic operators    */
		Fixed	operator + (const Fixed& other) const;
		Fixed	operator - (const Fixed& other) const;
		Fixed	operator * (const Fixed& other) const;
		Fixed	operator / (const Fixed& other) const;
		/*    4 arithmetic operators    */
		Fixed&	operator ++ (void);		//pre-increment
		Fixed	operator ++ (int);		//post-increment
		Fixed&	operator -- (void);		//pre-decrement
		Fixed	operator -- (int);		//post-decrement

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					_raw;
		static const int	_fraction_bit = 8;
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