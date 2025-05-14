#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("PresidentialPardonForm", "N/A", 25, 5)
{
	std::cout << "[PresidentialPardonForm] Default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm("PresidentialPardonForm", target, 25, 5)
{
	std::cout << "[PresidentialPardonForm] Parameterized constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src):
	AForm(src.getName(), src.getTarget(), src.getSignGrade(), src.getExeGrade())
{
	std::cout << "[PresidentialPardonForm] Copy constructor called." << std::endl;
	*this = src;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	std::cout << "[PresidentialPardonForm] Assignment operator called." << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "[PresidentialPardonForm] Destructor called." << std::endl;
}

/*________________Utils_________________*/
void	PresidentialPardonForm::doExe(void) const
{
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}