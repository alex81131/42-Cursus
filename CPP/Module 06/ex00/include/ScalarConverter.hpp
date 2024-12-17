#pragma once

# include <iostream>
# include <string>
# include <cstdlib>
# include <sstream>
# include <iomanip>			// For std::setprecision and std::fixed
# include <limits>

class	ScalarConverter
{
	public:
		enum Type
		{
			NONE,
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			OTHER
		};
		static void	convert(std::string s);
		// Static functions can be called "without an instance of the class",
		// 	because they are associated with the class itself rather than any specific object of the class.
		// (Non-static functions are tied to an instance of the class,
		// 	because they operate on the specific object's state (instance data).)
		// 1. Static functions cannot access non-static members or functions of the class.
		// 2. Cannot use this pointer.


	private:	// Must not be instanciable by users
		ScalarConverter(void);											// Default constructor
		ScalarConverter(const ScalarConverter& src);					// Copy constructor
		ScalarConverter&	operator = (const ScalarConverter& src);	// Assignment operator
		~ScalarConverter(void);											// Destructor

		static Type	getLiteralType(const std::string &s);
		static void	do_nan();
		static void	do_char(const std::string &s);
		static void	do_int(const std::string &s);
		static void	do_float(const std::string &s);
		static void	do_double(const std::string &s);
		static void	do_other(const std::string &s);
		static bool	is_float(const std::string &s);
		static bool	is_double(const std::string &s);
};

// 1. [Only one static method "convert"]
// 	taking a string literal as parameter from the user
// 	-> needs to be public
// 	-> Only one public static method "convert"
// 	other private static functions are allowed.

// 2. Static methods belong to the class itself, not to any instance of the class.
// 	This allows the convert method to be accessed directly via the class name
// 	(e.g., ScalarConverter::convert(...)), without the need for creating an instance.

// 3. String literal
// 	= const char* str

// 4. nan: Not a Number
// 	用來表示無法表示為有效數字的結果。
// 	NaN 並不等同於任何有效的數字，包括無窮大或零，因此它的主要作用是標識那些無意義或錯誤的數學運算結果。

// 5. double = double-precision floating-point number
// 	"float" is a 32-bit single-precision floating-point type
// 	"double" has double the precision (and thus double the size in memory) compared to a float