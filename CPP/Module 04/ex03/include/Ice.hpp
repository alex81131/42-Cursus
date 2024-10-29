#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	Ice: public AMateria
{
	public:
		Ice(void);								// Default constructor
		Ice(const Ice& src);					// Copy constructor
		Ice&	operator = (const Ice& src);	// Assignment operator
		~Ice(void);								// Destructor, treated as virtual by default

		Ice*	clone() const;
		void	use(ICharacter& target);		// Inherited memeber cannot be modified without declaration
};

#endif