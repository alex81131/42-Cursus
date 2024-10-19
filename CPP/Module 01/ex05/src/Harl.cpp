#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "[DEBUG] ";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void	Harl::info( void )
{
	std::cout << "[INFO] ";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[WARNING] ";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ERROR] ";
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
// Defines an array of member function pointers, pointing to the functions we're gonna use.
// Such implementation detail doesn't have to be declared in the header file.
	void	(Harl::*function[4])() =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string	lv[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

// Find the called function
	for (int i = 0; i < 4; i++)
		if (lv[i] == level)
			(this->*function[i])();
				return ;
}

// If you don't define a constructor, the compiler provides a default constructor
// (which does nothing except allocate memory and default-initialize member variables).

// array of member function pointers:
// 	void	(Harl::*function[4])()

// At the end of the for loop, both break and return are functionally equivalent.