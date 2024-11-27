#pragma once

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern(void);											// Default constructor
		Intern(const Intern& src);				// Copy constructor
		Intern&	operator = (const Intern& src);	// Assignment operator
		~Intern(void);											// Destructor

		AForm*	makeForm(std::string name, const std::string target);

	private:
		enum Type
		{
			SHRUB,
			ROBOT,
			PRESIDENT,
			OTHERS
		};

		Type	getFormType(const std::string& name);
};