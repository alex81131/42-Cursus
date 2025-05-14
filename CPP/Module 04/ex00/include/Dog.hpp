#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog: public Animal
{
	public:
		Dog(void);								// Default constructor
		Dog(const Dog& src);					// Copy constructor
		Dog&	operator=(const Dog& src);	// Assignment operator
		~Dog(void);								// Destructor, treated as virtual by default

		void	makeSound() const;

};


#endif