#pragma once

# include "AForm.hpp"
# include <fstream>

class	ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(void);													// Default constructor
		ShrubberyCreationForm(const std::string& target);								// Parameterized Constructor
		ShrubberyCreationForm(const ShrubberyCreationForm& src);						// Copy constructor
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& src);			// Assignment operator
		~ShrubberyCreationForm(void);											// Destructor

		/*______________Execution_______________*/
		void	doExe(void) const;
};