#include "ScalarConverter.hpp"

void	ScalarConverter::do_nan()
{
	std::cout << "-----------NaN-----------" << std::endl;
	std::cout << "Char:   " << "impossible" << std::endl;
	std::cout << "Int:    " << "impossible" << std::endl;
	std::cout << "Float:  " << "nan" << "f" << std::endl;
	std::cout << "Double: " << "nan" << std::endl;
}

void	ScalarConverter::do_char(const std::string &s)
{
	char	c = *s.begin();

	std::cout << "-----------Char-----------" << std::endl;
	std::cout << "Char:   '" << c << "'" << std::endl;
	std::cout << "Int:    " << static_cast<int>(c) << std::endl;
	std::cout << "Float:  " << std::fixed << std::setprecision(2) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(c) << std::endl;
}
// std::fixed:
// 	forces the output to be in fixed-point notation,
// 	meaning the number will be printed with a specified number of digits after the decimal point.
// 	ie. 1.23e+03 instead of 1230.0
// std::setprecision:
// 	By default, std::setprecision will control the total number of significant digits.
// But combined with std::fixed:
// 	sets the number of digits "after" the decimal point

void	ScalarConverter::do_int(const std::string &s)
{
	int	i = std::atoi(s.c_str());

	std::cout << "-----------Int-----------" << std::endl;
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << "Char: " << "impossible" << std::endl;
	else if (i < 32 || i > 126)
		std::cout << "Char:   " << "Not displayable" << std::endl;
	else
		std::cout << "Char:   '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "Int:    " << i << std::endl;
	std::cout << "Float:  " << std::fixed << std::setprecision(2) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(i) << std::endl;
}

void	ScalarConverter::do_float(const std::string &s)
{
	float	f = std::atof(s.c_str());		// std::atof returns double

	std::cout << "-----------Float-----------" << std::endl;
	// Integer check
	if (f != static_cast<char>(f) || f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
		std::cout << "Char:   " << "impossible" << std::endl;
	else if (f < 32 || f > 126)
		std::cout << "Char:   " << "Not displayable" << std::endl;
	else
		std::cout << "Char:   '" << static_cast<char>(f) << "'" << std::endl;
	// Integer check
	if (f != static_cast<int>(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << "Int:    " << "impossible" << std::endl;
	else
		std::cout << "Int:    " << static_cast<int>(f) << std::endl;
	std::cout << "Float:  " << std::fixed << std::setprecision(2) << f << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(f) << std::endl;
}

void	ScalarConverter::do_double(const std::string &s)
{
	double	d = std::atof(s.c_str());

	std::cout << "-----------Double-----------" << std::endl;
	if (d != static_cast<char>(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << "Char:   " << "impossible" << std::endl;
	else if (d < 32 || d > 126)
		std::cout << "Char:   " << "Not displayable" << std::endl;
	else
		std::cout << "Char:   '" << static_cast<char>(d) << "'" << std::endl;
	if (d != static_cast<int>(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "Int:    " << "impossible" << std::endl;
	else
		std::cout << "Int:    " << static_cast<int>(d) << std::endl;
	std::cout << "Float:  " << std::fixed << std::setprecision(2) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "Double: " << d << std::endl;
}

// Only the decimal notation will be used, Except for char cases.
// Don't have to handle:
// 1. "65e0" (scientific notation of 65 (A in ASCII), which is valid for float/double)
// 2. "0x10" (hexadecimal notation of 16, which is valid for integers but not for float or double)
void	ScalarConverter::do_other(void)
{
	std::cout << "-----------Other-----------" << std::endl;
	std::cout << "  [Decimal notation only]  " << std::endl;
	std::cout << "Char:   " << "impossible, wrong format." << std::endl;
	std::cout << "Int:    " << "impossible, wrong format." << std::endl;
	std::cout << "Float:  " << "impossible, wrong format." << std::endl;
	std::cout << "Double: " << "impossible, wrong format." << std::endl;
}

bool	ScalarConverter::is_float(const std::string &s)
{
	std::string::const_iterator	i;						// s.end() returns an iterator
	std::string::size_type		dotPos = s.find('.');	// s.find() returns in size_type

	if (dotPos ==  std::string::npos)					// npos for no position
		return false;
	for (i = s.begin(); i < s.end() - 1; ++i)
	{
		if (i - s.begin() - dotPos== 0)
			continue;
		if (!isdigit(*i))
			return false;
	}
	if (*i == 'f' || *i == 'F')
		return true;
	return false;
}
// Note:
// 	std::string::const_iterator is a random access iterator.
// 	This means you can safely use comparison operators like <, >, <=, >=.
// 	But with bidirectional or input iterators,
// 	comparisons < and > are not supported.
// 	Therefore should use != and ==.

bool	ScalarConverter::is_double(const std::string &s)
{
	std::string::const_iterator	i;						// s.end() returns an iterator
	std::string::size_type		dotPos = s.find('.');	// s.find() returns in size_type

	if (dotPos ==  std::string::npos)					// npos for no position
		return false;
	for (i = s.begin(); i != s.end(); ++i)				// i < s.end() also works
	{
		if (i - s.begin() - dotPos== 0)
			continue;
		if (!isdigit(*i))
			return false;
	}
	return true;
}