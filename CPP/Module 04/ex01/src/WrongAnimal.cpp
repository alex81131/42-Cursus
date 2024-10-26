#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "[WrongAnimal] Default constructor called." << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& src): Animal(src)
{
	std::cout << "[WrongAnimal] Copy constructor called." << std::endl;
	*this = src;
}

WrongAnimal&	WrongAnimal::operator = (const WrongAnimal& src)
{
	std::cout << "[WrongAnimal] Assignment operator called." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "[WrongAnimal] Destructor called." << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Stardenburdenhardenbart!" << std::endl;
}