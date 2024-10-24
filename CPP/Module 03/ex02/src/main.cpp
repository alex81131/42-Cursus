#include "FragTrap.hpp"

int main(void)
{
	FragTrap a("Ruby");
	// FragTrap a1;			// to show Default constructor
	// FragTrap a2(a);			// to show Copy constructor
	// FragTrap a3 = a;		// to show Copy assignment operator

	std::cout << "__________________________________________________________" << std::endl;
	a.attack("Arima Kousei");
	a.takeDamage(9);
	a.beRepaired(2);
	a.highFivesGuys();
	std::cout << "__________________________________________________________" << std::endl;
	return 0;
}