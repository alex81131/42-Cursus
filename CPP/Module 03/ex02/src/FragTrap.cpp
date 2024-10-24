#include "FragTrap.hpp"

// Explicit initialization
FragTrap::FragTrap(): ClapTrap()
{
	this->_hp = 100;
	this->_energy = 100;
	this->_atk = 30;
	std::cout << "[FragTrap] \"" << this->_name << "\" is created by the default constructor." << std::endl;
}

// Explicitly initialize with the arguments
FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_hp = 100;
	this->_energy = 100;
	this->_atk = 30;
	std::cout << "[FragTrap] \"" << this->_name << "\" is created by the constructor." << std::endl;
}

// Explicit initialization for copying
FragTrap::FragTrap(const FragTrap& src): ClapTrap(src)
{
	*this = src;
	std::cout << "[FragTrap] An object is copied from " << src._name << "." << std::endl;
}

FragTrap&	FragTrap::operator = (const FragTrap& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hp = src._hp;
		this->_energy = src._energy;
		this->_atk = src._atk;
	}
	std::cout << "[FragTrap] Copy assignment operator is called." << std::endl;
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[FragTrap] \"" << this->_name << "\" is destroyed." << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "[FragTrap] \"" << this->_name << "\" is sincerely requesting a high five with a heartfelt plea that glimmers like morning dew shining in her tear-filled eyes." << std::endl;
}