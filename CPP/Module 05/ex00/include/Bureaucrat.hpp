#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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

#endif

// what():
// 	a virtual method defined in the std::exception class that returns a C-style string (const char*)
// 	containing a description of the exception.
// And the throw() flag:
// 	Writing throw() after a function declaration was intended to signal that the function does not throw any exceptions,
// 	making it useful for functions like what() that must be exception-safe (e.g., those called during exception handling).

// std::ostream&	operator << (std::ostream& os, const Bureaucrat& src);
// 	os: reference to the destination stream
// 	src: constant reference to the object to be printed