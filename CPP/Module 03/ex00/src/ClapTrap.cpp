#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	_name("default_name"), _hp(10), _energy(10), _atk(0)
{
	std::cout << "A ClapTrap object " << this->_name << " is created by the default constructor." << std::endl;
}

ClapTrap::ClapTrap(std::string name):
	_name(name), _hp(10), _energy(10), _atk(0)
{
	std::cout << "A ClapTrap object " << this->_name << " is created by the constructor." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	*this = src;
	std::cout << "Object is copied from " << src._name << "." << std::endl;
}

ClapTrap::ClapTrap&	operator = (const ClapTrap& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hp = src._hp;
		this->_energy = src._energy;
		this->_atk = src._atk;
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "A ClapTrap object " << this->_name << " is destroyed." << std::endl;
}

void	attack(const std::string& target);
void	takeDamage(unsigned int amount);
void	beRepaired(unsigned int amount);