#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "Animal.hpp"

class	WrongAnimal: public Animal
{
	public:
		WrongAnimal(void);										// Default constructor
		WrongAnimal(const WrongAnimal& src);					// Copy constructor
		WrongAnimal&	operator=(const WrongAnimal& src);	// Assignment operator
		~WrongAnimal(void);								// Destructor

		void	makeSound() const;
};


#endif