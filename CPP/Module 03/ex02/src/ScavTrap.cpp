#include "ScavTrap.hpp"

// Need to explicitly initialize the base class (ClapTrap) part of the
// derived class (ScavTrap) when constructing an object.
ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hp = 100;
	this->_energy = 50;
	this->_atk = 20;
	std::cout << "A ScavTrap object " << this->_name << " is created by the default constructor." << std::endl;
}

// Explicitly initialize with the arguments
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_hp = 100;
	this->_energy = 50;
	this->_atk = 20;
	std::cout << "[ScavTrap] \"" << this->_name << "\" is created by the constructor." << std::endl;
}

// Explicit initialization for copying
ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap(src)
{
	*this = src;
	std::cout << "[ScavTrap] An object is copied from " << src._name << "." << std::endl;
}

ScavTrap&	ScavTrap::operator = (const ScavTrap& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hp = src._hp;
		this->_energy = src._energy;
		this->_atk = src._atk;
	}
	std::cout << "[ScavTrap] Copy assignment operator is called." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[ScavTrap] \"" << this->_name << "\" is destroyed." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	// Can't attack
	if (!this->_hp)
	{
		std::cout << "ScavTrap \"" << this->_name << "\" is dead, cannot attack." << std::endl;
		return ;
	}
	if (!this->_energy)
	{
		std::cout << "ScavTrap \"" << this->_name << "\" has no energy points, cannot attack." << std::endl;
		return ;
	}
	this->_energy--;
	// Attack
	std::cout << "ScavTrap \"" << this->_name << "\" attacks \"" << target;
	std::cout << "\", causing " << this->_atk << " points of damage!" << std::endl;
}
void	ScavTrap::guardGate()
{
	if (!this->_hp)
	{
		std::cout << "ScavTrap \"" << this->_name << "\" is dead, cannot guard gate." << std::endl;
		return ;
	}
	std::cout << "ScavTrap \"" << this->_name << "\" is now in Gate keeper mode." << std::endl;
}