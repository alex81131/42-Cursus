#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
// # include <string>

class	Animal
{
	public:
		Animal(void);							// Default constructor
		Animal(const std::string& type);		// Parameterized Constructor
		Animal(const Animal& src);				// Copy constructor
		Animal&	operator=(const Animal& src);	// Assignment operator
		virtual ~Animal(void);					// Destructor

		virtual void			makeSound() const;
		const std::string		getType() const;
// Polymorphism means "many forms."
// 	It allows a single function to behave differently depending on the type of object it’s working with.
// 	Hence the "virtual" keyword before the function "only" in the base class,
// 	though in the derived class it's allowed.

	protected:
		std::string	_type;

};


#endif