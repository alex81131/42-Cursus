#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap a("Ruby");
	// DiamondTrap a1;			// to show Default constructor
	// DiamondTrap a2(a);			// to show Copy constructor
	// DiamondTrap a3 = a;		// to show Copy assignment operator

	std::cout << "__________________________________________________________" << std::endl;
	a.attack("Arima Kousei");
	a.takeDamage(9);
	a.beRepaired(2);
	a.whoAmI();
	std::cout << "__________________________________________________________" << std::endl;
	return 0;
}