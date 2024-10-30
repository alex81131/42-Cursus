#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "[MateriaSource] Default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	std::cout << "[MateriaSource] Copy constructor called." << std::endl;
	*this = src;
}

MateriaSource&	MateriaSource::operator = (const MateriaSource& src)
{
	std::cout << "[MateriaSource] Assignment operator called." << std::endl;
	if (this != &src)
	{
		IMateriaSource::operator = (src);
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

MateriaSource::~MateriaSource(void)
{
	std::cout << "[MateriaSource] Destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
			if (this->_inventory[i])
				delete this->_inventory[i];
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int idx = 0; idx < 4; idx++)
	{
			if (!this->_inventory[idx])
			{
				this->_inventory[idx] = m;
				std::cout << "[MateriaSource] Learned a materia" << m->getType() << " at #" << idx << "." <<std::endl;
				return ;
			}
	}
	std::cout << "Error: slots full, cannot learn." << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int idx = 0; idx < 4; idx++)
	{
		if (this->_inventory[idx]->getType() == type)
		{
			std::cout << "[MateriaSource] Cloned the " << type << " materia." << std::endl;
			return _inventory[idx]->clone();
		}
	}
	std::cout << "Error: unknown materia." << std::endl;
	return 0;
}