#include "Cat.hpp"

Cat::Cat(void): _brain(new Brain)
{
	std::cout << "[Cat] Default constructor called." << std::endl;
	this->_type = "Cat";
	this->_brain->setIdeas("Meowmeow?");
	this->_brain->setIdeas("I want this human to pet me...");
	this->_brain->setIdeas("But for only 3 seconds!");
}
// A shallow copy only copies pointers and references.
// 	In contrast, a deep copy allocates new memory for the copy,
// 	ensuring it’s independent of the original.

Cat::Cat(const Cat& src): Animal(src), _brain(new Brain)
{
	std::cout << "[Cat] Copy constructor called." << std::endl;
	*this = src;
}

Cat&	Cat::operator=(const Cat& src)
{
	std::cout << "[Cat] Assignment operator called." << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		*this->_brain = *src._brain;
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "[Cat] Destructor called." << std::endl;
	delete this->_brain;
}

void	Cat::makeSound() const
{
	std::cout << "Meow~ ฅ^•⩊•^ฅ" << std::endl;
}

void	Cat::showIdeas(void) const
{
	_brain->showIdeas();
}