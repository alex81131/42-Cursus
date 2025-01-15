#pragma once

# include <iostream>	// cout
# include <algorithm>
# include <vector>

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

		void			addNumber(int nb);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		void			printAll(void) const;
		void			storeNumbers(unsigned int n);

		class			OutOfRangeException;
		class			NoRangeException;

	private:
		unsigned int		_n;
		unsigned int		_stored;
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