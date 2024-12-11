#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void):
	_signGrade(150), _exeGrade(150)
{
	std::cout << "[ScalarConverter] Default constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(const std::string& name, const std::string& target, int signGrade, int exeGrade):
	_name(name), _target(target), _signed(false), _signGrade(signGrade), _exeGrade(exeGrade)
{
	std::cout << "[ScalarConverter] Parameterized constructor called." << std::endl;
	if (signGrade < 1 || exeGrade < 1)
		throw ScalarConverter::GradeTooHighException();
	if (signGrade > 150 || exeGrade > 150)
		throw ScalarConverter::GradeTooLowException();
}

ScalarConverter::ScalarConverter(const ScalarConverter& src):
	_name(src._name), _target(src._target), _signed(src._signed), _signGrade(src._signGrade), _exeGrade(src._exeGrade)
{
	std::cout << "[ScalarConverter] Copy constructor called." << std::endl;
	*this = src;
}

ScalarConverter&	ScalarConverter::operator = (const ScalarConverter& src)
{
	std::cout << "[ScalarConverter] Assignment operator called." << std::endl;
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "[ScalarConverter] Destructor called." << std::endl;
}

/*_______________Get info_______________*/
const std::string&	ScalarConverter::getName() const
{
	return _name;
}

const std::string&	ScalarConverter::getTarget() const
{
	return _target;
}

bool	ScalarConverter::getSignStatus() const
{
	return _signed;
}

int	ScalarConverter::getSignGrade() const
{
	return _signGrade;
}

int	ScalarConverter::getExeGrade() const
{
	return _exeGrade;
}

/*______________Exceptions______________*/
const char*	ScalarConverter::GradeTooHighException::what() const throw()
{
	return "[Exception] Grade too high.\n";
}

const char*	ScalarConverter::GradeTooLowException::what() const throw()
{
	return "[Exception] Grade too low.\n";
}

const char*	ScalarConverter::NotSigned::what() const throw()
{
	return "[Exception] Form not signed.\n";
}

/*________________Utils_________________*/
void	ScalarConverter::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->_signGrade)
	{
		std::cout << b.getName() << " couldn’t sign " << this->_name << ", because:" << std::endl << std::endl;
		throw ScalarConverter::GradeTooLowException();
	}
	this->_signed = true;
	std::cout << b.getName() << " signed " << this->_name << ".\n";
}

void	ScalarConverter::execute(Bureaucrat const& executor) const
{
	if (this->_signed == false)
	{
		std::cout << executor.getName() << ": not signed, cannot execute." << std::endl;
		throw ScalarConverter::NotSigned();
	}
	if (executor.getGrade() > this->_exeGrade)
	{
		std::cout << executor.getName() << " cannot execute " << this->_name << ", because:" << std::endl << std::endl;
		throw ScalarConverter::GradeTooLowException();
	}
	std::cout << executor.getName() << " executed " << this->_name << "." << std::endl << std::endl;
	this->doExe();
}

std::ostream&	operator << (std::ostream& os, const ScalarConverter& src)
{
	os << "ScalarConverter name: " << src.getName() << "\n" 
		<< "\tSign status: " << src.getSignStatus() << "\n" 
		<< "\tGrade to sign: " << src.getSignGrade() << "\n" 
		<< "\tGrade to execute: " << src.getExeGrade() << "\n";
	return os;
}
