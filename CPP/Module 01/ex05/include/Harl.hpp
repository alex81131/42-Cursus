#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class	Harl
{
	public:
		void	complain( std::string level );

	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

#endif

// If you don't define a constructor, the compiler provides a default constructor
// (which does nothing except allocate memory and default-initialize member variables).