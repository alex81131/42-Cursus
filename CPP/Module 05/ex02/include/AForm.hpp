#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		AForm(void);													// Default constructor
		AForm(const std::string& name, const std::string& target, int signGrade, int exeGrade);	// Parameterized Constructor
		AForm(const AForm& src);										// Copy constructor
		AForm&	operator = (const AForm& src);							// Assignment operator
		virtual ~AForm(void);											// Destructor

		/*_______________Get info_______________*/
		const std::string&	getName() const;
		const std::string&	getTarget() const;

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
		class	NotSigned: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		/*________________Utils_________________*/
		void			beSigned(const Bureaucrat& b);
		void			execute(Bureaucrat const& executor) const;
		virtual void	doExe(void) const = 0;
		// Derived classes must provide their own implementation of execute to be concrete (instantiable).
		// The derived classes will inherit this function's declaration,
		// but they are required to define its behavior.

	private:
		const std::string	_name;
		std::string			_target;
		bool				_signed;
		const int			_signGrade;
		const int			_exeGrade;
};

std::ostream&	operator << (std::ostream& os, const AForm& src);

#endif