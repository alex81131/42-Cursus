#pragma once

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class	RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(void);													// Default constructor
		RobotomyRequestForm(const std::string& target);								// Parameterized Constructor
		RobotomyRequestForm(const RobotomyRequestForm& src);						// Copy constructor
		RobotomyRequestForm&	operator = (const RobotomyRequestForm& src);		// Assignment operator
		~RobotomyRequestForm(void);													// Destructor

		/*______________Execution_______________*/
		void	doExe(void) const;
};