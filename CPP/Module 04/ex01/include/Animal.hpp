#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

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

	protected:
		std::string	_type;

};

#endif