#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal
{
	public:
		Animal(void);							// Default constructor
		Animal(const std::string& type);		// Parameterized Constructor
		Animal(const Animal& src);				// Copy constructor
		Animal&	operator = (const Animal& src);	// Assignment operator
		virtual ~Animal(void);					// Destructor

		virtual void			makeSound() const = 0;	// Make `makeSound()` a pure virtual function
		const std::string		getType() const;
		// Any derived class (like Dog or Cat) will be required to
		// 	provide its own implementation of makeSound().

	protected:
		std::string	_type;

};

#endif

// Any class with at least one pure virtual function is considered an abstract class.
// Instantiate:
// 	make an instance out of something