#include "Form.hpp"

Form::Form(void):
	_signGrade(10), _exeGrade(20)
{
	std::cout << "[Form] Default constructor called." << std::endl;
}

Form::Form(const std::string& name, int signGrade, int exeGrade):
	_name(name), _signed(false), _signGrade(signGrade), _exeGrade(exeGrade)
{
	std::cout << "[Form] Parameterized constructor called." << std::endl;
	if (signGrade < 1 || exeGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || exeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& src):
	_name(src._name), _signed(src._signed), _signGrade(src._signGrade), _exeGrade(src._exeGrade)
{
	std::cout << "[Form] Copy constructor called." << std::endl;
	*this = src;
}

Form&	Form::operator = (const Form& src)
{
	std::cout << "[Form] Assignment operator called." << std::endl;
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

Form::~Form(void)
{
	std::cout << "[Form] Destructor called." << std::endl;
}

/*_______________Get info_______________*/
const std::string&	Form::getName() const
{
	return this->_name;
}

bool	Form::getSignStatus() const
{
	return this->_signed;
}

int	Form::getSignGrade() const
{
	return this->_signGrade;
}

int	Form::getExeGrade() const
{
	return this->_exeGrade;
}

/*______________Exceptions______________*/
const char*	Form::GradeTooHighException::what() const throw()
{
	return "[Exception] Grade too high.";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "[Exception] Grade too low.";
}

/*________________Utils_________________*/
void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->_signGrade)
	{
		std::cout << b.getName() << " couldn’t sign " << this->_name << ", because:\n";
		throw Form::GradeTooLowException();
	}
	this->_signed = true;
	std::cout << b.getName() << " signed " << this->_name << ".\n";
}

std::ostream&	operator << (std::ostream& os, const Form& src)
{
	os << "Form name: " << src.getName() << "\n" 
		<< "\tSign status: " << src.getSignStatus() << "\n" 
		<< "\tGrade to sign: " << src.getSignGrade() << "\n" 
		<< "\tGrade to execute: " << src.getExeGrade() << "\n";
	return os;
}
