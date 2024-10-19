#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}
void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Harl::others( void )
{
	std::cout << "[ Probably complaining about insignificant problems ]"<< std::endl;
}

t_type	Harl::get_type(const std::string level) const
{
	const std::string	lv[5] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
		"OTHERS"
	};

	for (int i = 0; i < 4; i++)
		if (lv[i] == level)
			return (t_type)i;
	return OTHERS;
}

void	Harl::complain( std::string level )
{
	void	(Harl::*f[5])() =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
		&Harl::others
	};
	switch(this->get_type(level))
	{
		case DEBUG:
			(this->*f[DEBUG])();
			std::cout << std::endl;
			// break ;
			// Intentional fallthrough
		case INFO:
			(this->*f[INFO])();
			std::cout << std::endl;
			// break ;
			// Intentional fallthrough
		case WARNING:
			(this->*f[WARNING])();
			std::cout << std::endl;
			// break ;
			// Intentional fallthrough
		case ERROR:
			(this->*f[ERROR])();
			std::cout << std::endl;
			break ;
		default:
			(this->*f[OTHERS])();
			std::cout << std::endl;
			break ;
	}
}

// Be careful with the enumeration of the function pointer and the enum t_type value.
// They should correspond correctly:
// typedef enum	e_type
// {
// 	DEBUG = 0,
// 	INFO = 1,
// 	WARNING = 2,
// 	ERROR = 3,
// 	OTHERS = 4
// }	t_type;
// void	(Harl::*f[5])() =
// {
// 	&Harl::debug = f[0],
// 	&Harl::info = f[1],
// 	&Harl::warning = f[2],
// 	&Harl::error = f[3],
// 	&Harl::others = f[4]
// };

// If there's no "break ;" at the end of the case,
// it will continue to execute the next case:
// 	VALUE1 executes case VALUE1 and VALUE2,
// 	and VALUE3 executes case VALUE3 and case VALUE4.
// 	(The comment "// Intentional fallthrough" is necessary to silence the -Werror error)
// switch(VALUE):		// behave differently depending on the VALUE
// {
// 	case VALUE1:
// 		ACTION;		// Intentional fallthrough
// 	case VALUE2:
// 	{
// 		ACTION;
// 		break ;
// 	}
// 	case VALUE3:
// 		ACTION;		// Intentional fallthrough
// 	case VALUE4:
// 	{
// 		ACTION;
// 		break ;
// 	}
// }