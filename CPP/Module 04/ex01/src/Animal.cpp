#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "[Animal] Default constructor called." << std::endl;
	this->_type = "Animal";
}

Animal::Animal(const Animal& src)
{
	std::cout << "[Animal] Copy constructor called." << std::endl;
	*this = src;
}

Animal&	Animal::operator=(const Animal& src)
{
	std::cout << "[Animal] Assignment operator called." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "[Animal] Destructor called." << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "zZzZzZzz.. ˚☽˚｡⋆(⸝⸝ᴗ﹏ᴗ⸝⸝) ᶻ 𝗓 𐰁" << std::endl;
}

const std::string	Animal::getType() const
{
	return this->_type;
}