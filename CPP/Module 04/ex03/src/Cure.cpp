#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	std::cout << "[Cure] Default constructor called." << std::endl;
}

Cure::Cure(const Cure& src): AMateria("cure")
{
	std::cout << "[Cure] Copy constructor called." << std::endl;
	*this = src;
}

Cure&	Cure::operator=(const Cure& src)
{
	std::cout << "[Cure] Assignment operator called." << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return *this;
}

Cure::~Cure(void)
{
	std::cout << "[Cure] Destructor called." << std::endl;
}

Cure*	Cure::clone() const
{
	std::cout << "An Cure object is cloned." << std::endl;
	return new Cure(*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}