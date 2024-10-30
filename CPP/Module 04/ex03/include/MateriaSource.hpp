#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);									// Default constructor
		MateriaSource(const MateriaSource& src);				// Copy constructor
		MateriaSource&	operator = (const MateriaSource& src);	// Assignment operator
		~MateriaSource(void);									// Destructor, treated as virtual by default

		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const &type);

	private:
		AMateria	*_inventory[4];
};

#endif