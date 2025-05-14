#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);									// Default constructor
		WrongCat(const std::string& type);				// Parameterized Constructor
		WrongCat(const WrongCat& src);					// Copy constructor
		WrongCat&	operator=(const WrongCat& src);	// Assignment operator
		~WrongCat(void);						// Destructor

		using WrongAnimal::makeSound;
};


#endif