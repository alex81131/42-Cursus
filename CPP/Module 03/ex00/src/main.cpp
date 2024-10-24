#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Ai");
	ClapTrap b("Dr. Aqua");
	ClapTrap c("Someone");
	// ClapTrap a1;			// to show Default constructor
	// ClapTrap a2(a);		// to show Copy constructor
	// ClapTrap a3 = a;		// to show Copy assignment operator

	std::cout << "__________________________________________________________" << std::endl;
	c.attack(a.getName());
	a.takeDamage(9);
	a.beRepaired(2);
	std::cout << "__________________________________________________________" << std::endl;
	c.attack(b.getName());
	b.takeDamage(10);
	std::cout << std::endl << "<<<" << c.getName() << " murdered " << b.getName() << ">>>" << std::endl << std::endl;
	b.attack(c.getName());
	b.beRepaired(10);
	std::cout << "__________________________________________________________" << std::endl;
	c.attack(a.getName());
	a.takeDamage(3);
	std::cout << "__________________________________________________________" << std::endl;
	for (int i = 10; i > 0; i--)
		c.attack(b.getName());
	c.beRepaired(10);
	std::cout << "__________________________________________________________" << std::endl;
	return 0;
}