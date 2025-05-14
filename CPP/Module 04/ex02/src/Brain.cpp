#include "Brain.hpp"

Brain::Brain(void): _idea_nb(0)
{
	std::cout << "[Brain] Default constructor called." << std::endl;
}

Brain::Brain(const Brain& src)
{
	std::cout << "[Brain] Copy constructor called." << std::endl;
	*this = src;
}

Brain&	Brain::operator=(const Brain& src)
{
	std::cout << "[Brain] Assignment operator called." << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
		this->_idea_nb = src._idea_nb;
	}
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "[Brain] Destructor called." << std::endl;
}

std::string	brain_to_string(int i)
{
	std::ostringstream	oss;

	oss << i;
	return oss.str();
}

void	Brain::setIdeas(std::string const& str)
{
	this->_ideas[this->_idea_nb % 100] = "idea[" + brain_to_string(this->_idea_nb + 1) + "]: " + str;
	this->_idea_nb++;
}

void	Brain::showIdeas(void) const
{
	if (_idea_nb > 0)
	{
		for (unsigned int i = 0; i < _idea_nb && i < 100; i++)
			std::cout << this->_ideas[i] << std::endl;
	}
	else
		std::cout << "Out of ideas!" << std::endl;
	
}