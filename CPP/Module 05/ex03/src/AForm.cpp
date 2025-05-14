#include "AForm.hpp"

AForm::AForm(void):
	_signGrade(150), _exeGrade(150)
{
	std::cout << "[AForm] Default constructor called." << std::endl;
}

AForm::AForm(const std::string& name, const std::string& target, int signGrade, int exeGrade):
	_name(name), _target(target), _signed(false), _signGrade(signGrade), _exeGrade(exeGrade)
{
	std::cout << "[AForm] Parameterized constructor called." << std::endl;
	if (signGrade < 1 || exeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || exeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src):
	_name(src._name), _target(src._target), _signed(src._signed), _signGrade(src._signGrade), _exeGrade(src._exeGrade)
{
	std::cout << "[AForm] Copy constructor called." << std::endl;
	*this = src;
}

AForm&	AForm::operator=(const AForm& src)
{
	std::cout << "[AForm] Assignment operator called." << std::endl;
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

AForm::~AForm(void)
{
	std::cout << "[AForm] Destructor called." << std::endl;
}

/*_______________Get info_______________*/
const std::string&	AForm::getName() const
{
	return _name;
}

const std::string&	AForm::getTarget() const
{
	return _target;
}

bool	AForm::getSignStatus() const
{
	return _signed;
}

int	AForm::getSignGrade() const
{
	return _signGrade;
}

int	AForm::getExeGrade() const
{
	return _exeGrade;
}

/*______________Exceptions______________*/
const char*	AForm::GradeTooHighException::what() const throw()
{
	return "[Exception] Grade too high.\n";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "[Exception] Grade too low.\n";
}

const char*	AForm::NotSigned::what() const throw()
{
	return "[Exception] Form not signed.\n";
}

/*________________Utils_________________*/
void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->_signGrade)
	{
		std::cout << b.getName() << " couldn’t sign " << this->_name << ", because:" << std::endl << std::endl;
		throw AForm::GradeTooLowException();
	}
	this->_signed = true;
	std::cout << b.getName() << " signed " << this->_name << ".\n";
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (this->_signed == false)
	{
		std::cout << executor.getName() << ": not signed, cannot execute." << std::endl;
		throw AForm::NotSigned();
	}
	if (executor.getGrade() > this->_exeGrade)
	{
		std::cout << executor.getName() << " cannot execute " << this->_name << ", because:" << std::endl << std::endl;
		throw AForm::GradeTooLowException();
	}
	std::cout << executor.getName() << " executed " << this->_name << "." << std::endl << std::endl;
	this->doExe();
}

std::ostream&	operator<<(std::ostream& os, const AForm& src)
{
	os << "AForm name: " << src.getName() << "\n" 
		<< "\tSign status: " << src.getSignStatus() << "\n" 
		<< "\tGrade to sign: " << src.getSignGrade() << "\n" 
		<< "\tGrade to execute: " << src.getExeGrade() << "\n";
	return os;
}
