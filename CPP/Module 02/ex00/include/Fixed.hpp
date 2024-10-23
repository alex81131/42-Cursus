#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& src);
		Fixed&	operator = (const Fixed& src);
		~Fixed(void);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_n;
		static const int	_fraction_bit = 8;
};

#endif

// Orthodox Canonical Form (OCF) refers to the practice of implementing the Rule of Three, which includes defining:
// 	1. a "destructor",
// 		(define a class to represent a type of object)
// 	2. "copy constructor",
// 		(implement a copy constructor to specify how instances of that class should be copied)
// 		Format:
// 			Fixed(const Fixed& src);
// 			"src": the source object, meaning the original that is being copied.
// 	3. and "copy assignment operator"
// 		This operator ensures that the current object is updated to have the same state as the other object,
// 		handling any necessary resource management (like deep copying) to avoid issues such as memory leaks or
// 		unintended sharing of resources.
// 		It typically returns a reference to the current object to allow for chaining assignments.
// for classes that manage resources.
// This approach enhances flexibility and prevents issues related to resource management.