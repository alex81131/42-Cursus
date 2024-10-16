#include "Zombie.hpp"

int	main() {
	Zombie	*z;
	int		nb = 11;

	z = zombieHorde(nb, "Lothlórien ");
	if (!z) {
		std::cerr << "Failed to create a horde of zombies." << std::endl;
		return 1;
	}
	std::cout << "A horde of zombie is created and needs be destroyed by calling delete:" << std::endl;
	for (int i = 0; i < nb; i++)
		z[i].announce();
	delete[] z;
	std::cout << "Zombie horde destroyed by delete[]." << std::endl;
	return 0;
}

// delete[]