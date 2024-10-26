#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# define SC_HP 100
# define SC_ENG 50
# define SC_ATK 20

# define FR_HP 100
# define FR_ENG 100
# define FR_ATK 30

// When two or more classes inherit from the same base class,
// 	and a derived class inherits from those classes,
// 	virtual inheritance ensures that only one instance
// 	of the base class is shared among the derived classes,
// 	preventing multiple instances of the base class from being created.
class	DiamondTrap: public ScavTrap, public FragTrap			// Need to put "virtual" in ScavTrap.hpp and FragTrap.hpp
{
	public:
		DiamondTrap(void);										// Default constructor
		DiamondTrap(std::string name);							// Parameterized Constructor
		DiamondTrap(const DiamondTrap& src);					// Copy constructor
		DiamondTrap&	operator = (const DiamondTrap& src);	// Assignment operator
		virtual ~DiamondTrap(void);										// Destructor

		using ScavTrap::attack;
		void	whoAmI();

	private:
		std::string	_name;

};


#endif

// Class:
// 	A class is like a blueprint or template that defines the structure and behavior of objects.
// Object:
// 	An object is an instance of a class.