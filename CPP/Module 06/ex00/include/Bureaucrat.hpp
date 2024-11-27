#pragma once

# include <iostream>
# include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
	public:
		Bureaucrat(void);								// Default constructor
		Bureaucrat(const std::string& name, int grade);	// Parameterized Constructor
		Bureaucrat(const Bureaucrat& src);				// Copy constructor
		Bureaucrat&	operator = (const Bureaucrat& src);	// Assignment operator
		~Bureaucrat(void);								// Destructor

		/*_______________Get info_______________*/
		const std::string&	getName() const;
		int					getGrade() const;

		/*_____________Change grade_____________*/
		void				increment();
		void				decrement();

		/*_______Invalid grade exceptions_______*/// also called nest class
		class				GradeTooHighException;
		class				GradeTooLowException;

		/*________________Utils_________________*/
		void	signForm(AForm& form);
		void	executeForm(AForm const& form);

	private:
		const std::string	_name;
		int					_grade;
};

/*_______Invalid grade exceptions_______*/
// Inherit from the standard C++ std::exception class
class	Bureaucrat::GradeTooHighException: public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class	Bureaucrat::GradeTooLowException: public std::exception
{
	public:
		virtual const char*	what() const throw();
};

std::ostream&	operator << (std::ostream& os, const Bureaucrat& src);