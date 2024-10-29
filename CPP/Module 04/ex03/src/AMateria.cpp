#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "[AMateria] Default constructor called." << std::endl;
	this->_type = "";
}

AMateria::AMateria(std::string const & type): _type(type)
{
	std::cout << "[AMateria] Parameterized Constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& src)
{
	std::cout << "[AMateria] Copy constructor called." << std::endl;
	*this = src;
}

AMateria&	AMateria::operator = (const AMateria& src)
{
	std::cout << "[AMateria] Assignment operator called." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

AMateria::~AMateria(void)
{
	std::cout << "[AMateria] Destructor called." << std::endl;
}

const std::string&	AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "Use Materia to " << target.getName() << " in Materia class." << std::endl;
}