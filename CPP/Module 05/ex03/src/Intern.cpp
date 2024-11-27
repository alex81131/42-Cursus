#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "[Intern] Default constructor called." << std::endl;
}

Intern::Intern(const Intern& src)
{
	std::cout << "[Intern] Copy constructor called." << std::endl;
	*this = src;
}

Intern&	Intern::operator = (const Intern& src)
{
	std::cout << "[Intern] Assignment operator called." << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

Intern::~Intern(void)
{
	std::cout << "[Intern] Destructor called." << std::endl;
}

AForm*	Intern::makeForm(std::string name, const std::string target)
{
	AForm	*result = NULL;

	// Case insensitivity for easier parsing
	for (std::string::iterator c = name.begin(); c < name.end(); c++)
		*c = std::tolower(*c);
	switch(this->getFormType(name))
	{
		case SHRUB:
			result = new ShrubberyCreationForm(target);
			break;
		case ROBOT:
			result = new RobotomyRequestForm(target);
			break;
		case PRESIDENT:
			result = new PresidentialPardonForm(target);
			break;
		default:
			std::cerr << "Error: Form not found." << std::endl;
			return NULL;
	}
	std::cout << "[Intern] Form \"" << result->getName();
	std::cout << "\", targeting >>" << result->getTarget() << "<< created." << std::endl;
	return result;
}

Intern::Type	Intern::getFormType(const std::string& name)
{
	const std::string	type[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
		if (name == type[i])
			return (Type)i;
	return OTHERS;
}