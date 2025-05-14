#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure: public AMateria
{
	public:
		Cure(void);								// Default constructor
		Cure(const Cure& src);					// Copy constructor
		Cure&	operator=(const Cure& src);	// Assignment operator
		~Cure(void);								// Destructor, treated as virtual by default

		Cure*	clone() const;
		void	use(ICharacter& target);
};

#endif