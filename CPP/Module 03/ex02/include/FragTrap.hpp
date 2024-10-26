#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

// Inheritance:
// 	FragTrap is a derived class that inherits from the base class ClapTrap
// 	using public inheritance.
class	FragTrap: public ClapTrap
{
	public:
		FragTrap(void);									// Default constructor
		FragTrap(std::string name);						// Parameterized Constructor
		FragTrap(const FragTrap& src);					// Copy constructor
		FragTrap&	operator = (const FragTrap& src);	// Assignment operator
		virtual ~FragTrap(void);								// Destructor

		void	highFivesGuys(void);

};


#endif

// Class:
// 	A class is like a blueprint or template that defines the structure and behavior of objects.
// Object:
// 	An object is an instance of a class.