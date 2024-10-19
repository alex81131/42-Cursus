#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

typedef enum	e_type
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	OTHERS
}	t_type;

class	Harl
{
	public:
		void	complain( std::string level );

	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		void	others( void );
		t_type	get_type(const std::string level) const;
};

#endif

// By default:
// typedef enum	e_type
// {
// 	DEBUG = 0,
// 	INFO = 1,
// 	WARNING = 2,
// 	ERROR = 3,
// 	OTHERS = 4
// }	t_type;

// t_type needs to be declared before any usage.