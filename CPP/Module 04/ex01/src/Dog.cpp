#include "Dog.hpp"

Dog::Dog(void): _brain(new Brain)
{
	std::cout << "[Dog] Default constructor called." << std::endl;
	this->_type = "Dog";
	this->_brain->setIdeas("I wanna eat cakes!");
}

Dog::Dog(const Dog& src): Animal(src), _brain(new Brain)
{
	std::cout << "[Dog] Copy constructor called." << std::endl;
	*this = src;
}

Dog&	Dog::operator=(const Dog& src)
{
	std::cout << "[Dog] Assignment operator called." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "[Dog] Destructor called." << std::endl;
	delete this->_brain;
}

void	Dog::makeSound() const
{
	std::cout << "Woof! Woof! ૮⍝• ᴥ •⍝ა" << std::endl;
}

void	Dog::showIdeas(void) const
{
	_brain->showIdeas();
}