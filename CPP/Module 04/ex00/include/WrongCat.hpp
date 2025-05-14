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
		//The "using" directive would only be needed if you want to make that
		//protected function accessible at a different access level in the derived class (e.g., making it public).
};


#endif