#include "Data.hpp"

Data::Data(void):
	_c('A'), _i(12), _d(11.1), _s("Default"), _ptr(NULL)
{
	std::cout << "[Data] Constructed with default values." << std::endl;
	this->printData();
}

Data::Data(char c): _c(c)
{
	std::cout << "[Data] Constructed with char." << std::endl;
	this->printData();
}

Data::Data(int i): _i(i)
{
	std::cout << "[Data] Constructed with int." << std::endl;
	this->printData();
}

Data::Data(double d): _d(d)
{
	std::cout << "[Data] Constructed with double." << std::endl;
	this->printData();
}

Data::Data(const std::string &s): _s(s)
{
	std::cout << "[Data] Constructed with string." << std::endl;
	this->printData();
}

Data::Data(void *ptr): _ptr(ptr)
{
	std::cout << "[Data] Constructed with pointer." << std::endl;
	this->printData();
}

Data::Data(char c, int i, double d, const std::string &s, void *ptr):
	_c(c), _i(i), _d(d), _s(s), _ptr(ptr)
{
	std::cout << "[Data] Constructed with new values." << std::endl;
	this->printData();
}


Data::Data(const Data& src)
{
	*this = src;
}

Data&	Data::operator = (const Data& src)
{
	if (this != &src)
	{
		_c = src._c;
		_i = src._i;
		_d = src._d;
		_s = src._s;
		_ptr = src._ptr;
	}
	return *this;
}

Data::~Data(void) {}

void	Data::printData(void)
{
	std::cout <<
		"char:    " << this->_c << std::endl <<
		"int:     " << this->_i << std::endl <<
		"double:  " << this->_d << std::endl <<
		"string:  " << this->_s << std::endl <<
		"pointer: " << this->_ptr << std::endl;
}