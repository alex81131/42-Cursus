#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("Ruby");
	// ScavTrap a1;			// to show Default constructor
	// ScavTrap a2(a);			// to show Copy constructor
	// ScavTrap a3 = a;		// to show Copy assignment operator

	std::cout << "__________________________________________________________" << std::endl;
	a.attack("Arima");
	a.takeDamage(9);
	a.beRepaired(2);
	a.guardGate();
	std::cout << "__________________________________________________________" << std::endl;
	return 0;
}