#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class	ClapTrap
{
	public:
		ClapTrap(void);									// Default constructor
		ClapTrap(std::string name);						// Parameterized Constructor
		ClapTrap(const ClapTrap& src);					// Copy constructor
		ClapTrap&	operator=(const ClapTrap& src);	// Assignment operator
		~ClapTrap(void);								// Destructor

		void				attack(const std::string& target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

		const std::string&	getName(void) const;

	private:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_energy;
		unsigned int	_atk;

};


#endif

// Class:
// 	A class is like a blueprint or template that defines the structure and behavior of objects.
// Object:
// 	An object is an instance of a class.