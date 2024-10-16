#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

	if (N <= 0) {
		std::cerr << "Error: N <= 0, no zombie created." << std::endl;
		return NULL;
	}
	Zombie	*horde = new Zombie[N];
	if (!horde) {
		std::cerr << "Memory allocation failed." << std::endl;
		return NULL;
	}
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return (horde);
}

// NULL is C++ is nullptr

// new Zombie[N] creates an array of N objects of type Zombie and returns a pointer to the first element in this array.