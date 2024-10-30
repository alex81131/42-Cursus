#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria(void);									// Default constructor
		AMateria(std::string const & type);				// Parameterized Constructor
		AMateria(const AMateria& src);					// Copy constructor
		AMateria&	operator = (const AMateria& src);	// Assignment operator
		virtual ~AMateria(void);						// Destructor

		std::string const&	getType() const; //Returns the materia type

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

	protected:
		std::string			_type;
};

#endif