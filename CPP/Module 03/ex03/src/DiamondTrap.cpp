#include "DiamondTrap.hpp"

// Explicit initialization
// DiamondTrap inherits from both ScavTrap and FragTrap,
// 	but FragTrap is the second base class in the constructor list,
// 	the value of _energy from FragTrap overrides the value from ScavTrap. 
DiamondTrap::DiamondTrap(): ClapTrap()
{
	// this->_hp = FR_HP;		// Automatically overridden
	this->_energy = SC_ENG;
	// this->_atk = FR_ATK		// Automatically overridden
	std::cout << "[DiamondTrap] \"" << this->_name << "\" is created by the default constructor." << std::endl;
}
// Cannot:
// 	this->_hp = FragTrap::_hp;
// 	this->_energy = ScavTrap::_energy;
// 	this->_atk = FragTrap::_atk;
// because DiamondTrap inherits from both ScavTrap and FragTrap using virtual inheritance from ClapTrap.
// 	This means that there will only be one instance of ClapTrap shared between ScavTrap and FragTrap.
// 	And with the order of inheritance: class	DiamondTrap: public ScavTrap, public FragTrap
// 	FragTrap will always overwrite ScavTrap's attributes.

// Explicitly initialize with the arguments
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	this->_name = name;
	this->_energy = SC_ENG;
	std::cout << "[DiamondTrap] \"" << this->_name << "\" is created by the constructor." << std::endl;
	// Debug
	std::cout << "[DiamondTrap] " << this->_name << " has " << this->_hp << " hit points, ";
	std::cout << this->_energy << " energy points and " << this->_atk << " attack damage." << std::endl;
}

// Explicit initialization for copying
DiamondTrap::DiamondTrap(const DiamondTrap& src): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	*this = src;
	std::cout << "[DiamondTrap] An object is copied from " << src._name << "." << std::endl;
}

DiamondTrap&	DiamondTrap::operator = (const DiamondTrap& src)
{
	if (this != &src)
	{
		this->_name = src._name + "_clap_trap";
		ClapTrap::operator = (src);
	}
	std::cout << "[DiamondTrap] Copy assignment operator is called." << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "[DiamondTrap] \"" << this->_name << "\" is destroyed." << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "[DiamondTrap] " << this->_name << ": My DiamondTrap name is " << this->_name;
	std::cout << " and my ClapTrap name is " << ClapTrap::_name << "." << std::endl;
}