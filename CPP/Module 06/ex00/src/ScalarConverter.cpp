#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void) src;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src)
{
	(void) src;
	return *this;
}

ScalarConverter::~ScalarConverter(void) {}

/*_______________Breakdown_______________*/
ScalarConverter::Type	ScalarConverter::getLiteralType(const std::string &s)
{
	// nan
	if (s == "nan" || s == "nanf" || s == "+nan" || s == "-nan" || s == "+nanf" || s == "-nanf")
		return NONE;
	// char
	if (s.length() == 1 && !isdigit(*s.begin()))
		return CHAR;
	// int
	int	i = std::atoi(s.c_str());
	std::stringstream	ss;
	ss << i;
	// If the literal stays the same after the integer transformation, it is indeed an integer.
	// 	ss.str(): returns the current content of the string stream as a std::string
	if (s == ss.str())
		return INT;
	// float
	if (s == "inff" || s == "+inff" || s == "-inff" || is_float(s))
		return FLOAT;
	// double
	if (s == "inf" || s == "+inf" || s == "-inf" || is_double(s))
		return DOUBLE;
	return OTHER;
}
// s.begin() is an iterator, not a pointer, but it behaves similarly to a pointer in many ways.
// 	Specifically, it points to the first element of the string s.
// 	An iterator in C++ is an object that provides access to elements in a container (like std::string),
// 	and it can be dereferenced to access the value it points to.
// *s.begin() dereferences the iterator, giving you the first character of the string s.
// 	So in this case: !isdigit(*s.begin()) = !isdigit(s[0])
// c_str():
// 	from std::string to C-style string (i.e., const char*)

void	ScalarConverter::convert(std::string s)
{
	switch(getLiteralType(s))
	{
		case NONE:
			do_nan();
			break;
		case CHAR:
			do_char(s);
			break;
		case INT:
			do_int(s);
			break;
		case FLOAT:
			do_float(s);
			break;
		case DOUBLE:
			do_double(s);
			break;
		default:
			do_other(s);
			break;
	}
}