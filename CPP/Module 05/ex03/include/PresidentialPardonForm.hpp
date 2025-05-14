#pragma once

# include "AForm.hpp"
# include <fstream>

class	PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(void);											// Default constructor
		PresidentialPardonForm(const std::string& target);						// Parameterized Constructor
		PresidentialPardonForm(const PresidentialPardonForm& src);				// Copy constructor
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);	// Assignment operator
		~PresidentialPardonForm(void);											// Destructor

		/*______________Execution_______________*/
		void	doExe(void) const;
};