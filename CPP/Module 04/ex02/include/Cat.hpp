#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
#include "Brain.hpp"

class	Cat: public Animal
{
	public:
		Cat(void);								// Default constructor
		Cat(const Cat& src);					// Copy constructor
		Cat&	operator = (const Cat& src);	// Assignment operator
		~Cat(void);								// Destructor, treated as virtual by default

		void	makeSound() const;
		void	showIdeas(void) const;

	private:
		Brain	*_brain;
};


#endif