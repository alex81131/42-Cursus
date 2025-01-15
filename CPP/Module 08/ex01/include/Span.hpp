#pragma once

# include <iostream>	// cout
# include <algorithm>	// sort, max_element, min_elenemt
# include <vector>
# include <limits>		// numeric limits

// A container in C++ is a conceptual "box" designed to
// 	store and manage collections of objects or data elements.

class	Span
{
	public:
		Span(void);								// Default constructor
		Span(unsigned int n);					// Parameterized Constructor
		Span(const Span& src);					// Copy constructor
		Span&	operator = (const Span& src);	// Assignment operator
		~Span(void);							// Destructor

		void			addNumber(int value);
		void			addNumber(int value, int n);	// Store "value" n times
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		void			printAll(void) const;
		void			storeNumbers(unsigned int n);	// Store n random numbers

		class			OutOfRangeException;
		class			NoRangeException;

	private:
		unsigned int		_maxSize;
		std::vector<int>	_cont;
};

class	Span::OutOfRangeException: public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class	Span::NoRangeException: public std::exception
{
	public:
		virtual const char*	what() const throw();
};