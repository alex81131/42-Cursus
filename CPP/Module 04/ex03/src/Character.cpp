#include "Character.hpp"

Character::Character(void)
{
	std::cout << "[Character] Default constructor called." << std::endl;
}

Character::Character(std::string const& name): _name(name)
{
	std::cout << "[Character] Parameterized Constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
}

Character::Character(const Character& src)
{
	std::cout << "[Character] Copy constructor called." << std::endl;
	*this = src;
}

Character&	Character::operator = (const Character& src)
{
	std::cout << "[Character] Assignment operator called." << std::endl;
	if (this != &src)
	{
		ICharacter::operator=(src);
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character(void)
{
	std::cout << "[Character] Destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
			if (this->_inventory[i])
				delete this->_inventory[i];
}

std::string const&	Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	for (int idx = 0; idx < 4; idx++)
	{
			if (!this->_inventory[idx])
			{
				this->_inventory[idx] = m;
				std::cout << "[Character] " << this->_name << " is equipped with a materia " << m->getType() << " at #" << idx << "." <<std::endl;
				return ;
			}
	}
	std::cout << "Error: inventory full, cannot equip." << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Error: invalid index number." << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout << "Error: empty slot, cannot unequip." << std::endl;
		return ;
	}
	this->_inventory[idx] = 0;
	std::cout << "[Character] Materia #" << idx << " has been unequipped from " << this->_name << "." << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Error: invalid index number." << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout << "Error: empty slot, cannot use." << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}
