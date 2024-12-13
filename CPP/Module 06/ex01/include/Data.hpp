#pragma once

# include <iostream>
# include <string>

class	Data
{
	public:
		Data(void);								// Default constructor

		// Parameterized Constructor
		Data(char c);
		Data(int i);
		Data(double d);
		Data(const std::string &s);
		Data(void *ptr);
		Data(char c, int i, double d, const std::string &s, void *ptr);

		Data(const Data& src);					// Copy constructor
		Data&	operator = (const Data& src);	// Assignment operator
		~Data(void);							// Destructor

		void	printData(void);

	private:
		char		_c;
		int			_i;
		double		_d;
		std::string	_s;
		void		*_ptr;
};