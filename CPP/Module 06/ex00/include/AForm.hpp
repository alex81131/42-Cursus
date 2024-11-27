#pragma once

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		AForm(void);													// Default constructor
		AForm(const std::string& name, const std::string& target, int signGrade, int exeGrade);	// Parameterized Constructor
		AForm(const AForm& src);										// Copy constructor
		AForm&	operator = (const AForm& src);							// Assignment operator
		virtual ~AForm(void);											// Destructor

		/*_______________Get info_______________*/
		const std::string&	getName() const;
		const std::string&	getTarget() const;

		bool				getSignStatus() const;
		int					getSignGrade() const;
		int					getExeGrade() const;

		/*______________Exceptions______________*/
		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class	NotSigned: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		/*________________Utils_________________*/
		void			beSigned(const Bureaucrat& b);
		void			execute(Bureaucrat const& executor) const;
		virtual void	doExe(void) const = 0;
		// Derived classes must provide their own implementation of execute to be concrete (instantiable).
		// The derived classes will inherit this function's declaration,
		// but they are required to define its behavior.

	private:
		const std::string	_name;
		std::string			_target;
		bool				_signed;
		const int			_signGrade;
		const int			_exeGrade;
};

std::ostream&	operator << (std::ostream& os, const AForm& src);

// #pragma once:
// 	a preprocessor directive in C++ that ensures a header file is included only once in a single compilation.
// 	It prevents duplicate inclusions of the same header file, which could cause errors or redefinition issues.

// |Aspect     |#pragma once                                          |#ifndef / #define include guards              |
// |-----------|------------------------------------------------------|----------------------------------------------|
// |Simplicity | Cleaner, one-line directive.                         |Requires three lines of boilerplate code.     |
// |Speed      | Faster on some compilers due to no text comparison.  |May involve string comparison for macro names.|
// |Portability| Not universally supported (rare in modern compilers).|Supported by all C++ compilers.               |
// |Uniqueness | Guaranteed unique by file path.                      |Relies on naming convention uniqueness.       |
// |Debugging  | Easier to debug when header issues occur.            |Harder to debug if guard names conflict.      |

// Use #pragma once:
// 	1. If you're targeting modern compilers (e.g., GCC, Clang, MSVC).
// 	2. For simpler and cleaner code.
// #pragma once is preferred for modern projects due to its simplicity and performance benefits.
// 	However, #ifndef / #define is better for ensuring compatibility in environments where #pragma once may not be supported.