#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	_name("default_name"), _hp(10), _energy(10), _atk(0)
{
	std::cout << "[ClapTrap] " << this->_name << " is created by the default constructor." << std::endl;
}

ClapTrap::ClapTrap(std::string name):
	_name(name), _hp(10), _energy(10), _atk(0)
{
	std::cout << "[ClapTrap] \"" << this->_name << "\" is created by the constructor." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	*this = src;
	std::cout << "[ClapTrap] An object is copied from " << src._name << "." << std::endl;
}

ClapTrap&	ClapTrap::operator = (const ClapTrap& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hp = src._hp;
		this->_energy = src._energy;
		this->_atk = src._atk;
	}
	std::cout << "[ClapTrap] Copy assignment operator is called." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "[ClapTrap] \"" << this->_name << "\" is destroyed." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	// Can't attack
	if (!this->_hp)
	{
		std::cout << "ClapTrap \"" << this->_name << "\" is dead, cannot attack." << std::endl;
		return ;
	}
	if (!this->_energy)
	{
		std::cout << "ClapTrap \"" << this->_name << "\" has no energy points, cannot attack." << std::endl;
		return ;
	}
	this->_energy--;
	// Attack
	std::cout << "ClapTrap \"" << this->_name << "\" attacks " << target;
	std::cout << ", causing " << this->_atk << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_hp)
	{
		std::cout << "ClapTrap \"" << this->_name << "\" is dead already." << std::endl;
		return ;
	}
	std::cout << "ClapTrap \"" << this->_name << "\" receives " << amount << " points of damage!" << std::endl;
	this->_hp -= amount;
	if (this->_hp <= 0)
		std::cout << "ClapTrap \"" << this->_name << "\" died." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_hp)
	{
		std::cout << "ClapTrap \"" << this->_name << "\" is dead, cannot repair itself." << std::endl;
		return ;
	}
	if (!this->_energy)
	{
		std::cout << "ClapTrap \"" << this->_name << "\" has no energy points, cannot repair itself." << std::endl;
		return ;
	}
	this->_energy--;
	this->_hp += amount;
	std::cout << "ClapTrap \"" << this->_name << "\" restores " << amount << " hit points!" << std::endl;
}

const std::string&	ClapTrap::getName(void) const
{
	return this->_name;
}