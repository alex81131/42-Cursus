#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	std::cout << "[Ice] Default constructor called." << std::endl;
}

Ice::Ice(const Ice& src): AMateria("ice")
{
	std::cout << "[Ice] Copy constructor called." << std::endl;
	*this = src;
}

Ice&	Ice::operator=(const Ice& src)
{
	std::cout << "[Ice] Assignment operator called." << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return *this;
}

Ice::~Ice(void)
{
	std::cout << "[Ice] Destructor called." << std::endl;
}

Ice*	Ice::clone() const
{
	std::cout << "An Ice object is cloned." << std::endl;
	return new Ice(*this);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}