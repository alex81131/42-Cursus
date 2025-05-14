#pragma once

// Reverse Polish notation: use stack structure to reduce the access to the main memory (in PC)
// without the need of parentheses.
// ie.			3 + 4		→	3 4 +
//		(3 + 4) × (5 + 6)	→	3 4 + 5 6 + ×
# include <iostream>	// cout
# include <fstream>		// file stream: reading and writing file stream
# include <sstream>		// string stream
# include <string>		// getline
# include <stdexcept>	// std::logic_error for logical mistakes, such as invalid arguments or precondition violations.
# include <stack>
// std::stack simplifies RPN evaluation, since numbers are stored and retrieved in the correct order for processing.
// stack follows the LIFO (Last In, First Out) principle, which matches how RPN works.
// 	(In RPN, operands are pushed onto the stack, and when an operator is encountered, it pops the operands from the stack, performs the operation, and pushes the result back onto the stack.)

class	RPN
{
	public:
		RPN(void);								// Default constructor
		RPN(const RPN& src);					// Copy constructor
		RPN&	operator=(const RPN& src);	// Assignment operator
		~RPN(void);								// Destructor

		double	calculation(const std::string& str);

	private:
		std::stack<double>	_stack;

		void	do_operator(const std::string& token);
		void	do_number(const std::string& token);
};