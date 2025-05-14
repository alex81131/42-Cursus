#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat: public Animal
{
	public:
		Cat(void);								// Default constructor
		Cat(const Cat& src);					// Copy constructor
		Cat&	operator=(const Cat& src);	// Assignment operator
		~Cat(void);								// Destructor, treated as virtual by default
												// cuz the base class destructor is declared virtual already

		void	makeSound() const;

};


#endif