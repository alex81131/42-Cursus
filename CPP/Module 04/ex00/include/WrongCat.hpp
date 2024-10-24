#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

// Inheritance:
// 	ScavTrap is a derived class that inherits from the base class ClapTrap
// 	using public inheritance.
class	ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap(void);									// Default constructor
		ScavTrap(std::string name);						// Parameterized Constructor
		ScavTrap(const ScavTrap& src);					// Copy constructor
		ScavTrap&	operator = (const ScavTrap& src);	// Assignment operator
		virtual ~ScavTrap(void);								// Deconstructor

		void	attack(const std::string& target);
		void	guardGate();

};


#endif

// Class:
// 	A class is like a blueprint or template that defines the structure and behavior of objects.
// Object:
// 	An object is an instance of a class.