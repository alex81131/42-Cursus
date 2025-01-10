#pragma once

# include <iostream>	// cout, exception
# include <sstream>		// ostream

template <typename T>
class	Array
{
	public:
		Array(void);							// Default constructor
		Array(unsigned int n);					// Parameterized Constructor
		Array(const Array& src);				// Copy constructor
		Array&	operator = (const Array& src);	// Assignment operator
		~Array(void);							// Destructor

		T&				operator [] (unsigned int i);
		const T&		operator [] (unsigned int i) const;
		unsigned int	size(void) const;
		class			OutOfRangeException;

	private:
		unsigned int	_size;
		T				*_arr;
};

template <typename T>
class Array<T>::OutOfRangeException: public std::exception
{
	public:
		virtual const char*	what() const throw();
};

template <typename T>
std::ostream&	operator << (std::ostream &o, const Array<T> &src);

# include "Array.tpp"
// Either you write everything in a single hpp (implementation after declaration),
// 	or you write the declaration and then #include the implementation afterwards, as shown above.