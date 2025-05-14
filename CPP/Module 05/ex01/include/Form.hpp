#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public:
		Form(void);													// Default constructor
		Form(const std::string& name, int signGrade, int exeGrade);	// Parameterized Constructor
		Form(const Form& src);										// Copy constructor
		Form&	operator=(const Form& src);						// Assignment operator
		~Form(void);												// Destructor

		/*_______________Get info_______________*/
		const std::string&	getName() const;
		bool				getSignStatus() const;
		int					getSignGrade() const;
		int					getExeGrade() const;

		/*______________Exceptions______________*/
		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		/*________________Utils_________________*/
		void	beSigned(const Bureaucrat& b);

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_exeGrade;
};

std::ostream&	operator<<(std::ostream& os, const Form& src);

#endif