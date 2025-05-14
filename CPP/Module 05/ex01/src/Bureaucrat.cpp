#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	std::cout << "[Bureaucrat] Default constructor called." << std::endl;
}

// Use "throw" to cast exceptions
Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade)
{
	std::cout << "[Bureaucrat] Parameterized constructor called." << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	std::cout << "[Bureaucrat] Copy constructor called." << std::endl;
	*this = src;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << "[Bureaucrat] Assignment operator called." << std::endl;
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "[Bureaucrat] Destructor called." << std::endl;
}
/*_______________Get info_______________*/
const std::string&	Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

/*_____________Change grade_____________*/
void	Bureaucrat::increment()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	std::cout << _name << " incremented to " << _grade << "." << std::endl;
}

void	Bureaucrat::decrement()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	std::cout << _name << " decremented to " << _grade << "." << std::endl;
}

/*_______Invalid grade exceptions_______*/
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "[Exception] Grade too high.";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "[Exception] Grade too low.";
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return os;
}

/*________________Utils_________________*/
void	Bureaucrat::signForm(Form& form)
{
	form.beSigned(*this);
}