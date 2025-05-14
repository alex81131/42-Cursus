#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

class	Brain
{
	public:
		Brain(void);							// Default constructor
		Brain(const Brain& src);				// Copy constructor
		Brain&	operator=(const Brain& src);	// Assignment operator
		~Brain(void);							// Destructor, treated as virtual by default

		void			setIdeas(std::string const& str);
		void			showIdeas(void) const;

	private:
		std::string		_ideas[100];
		unsigned int	_idea_nb;
};


#endif