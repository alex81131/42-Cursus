#include "Zombie.hpp"

int	main() {
	Zombie	z1("Barbara");
	Zombie	*z2 = newZombie("David");

	std::cout << "A zombie is created, allocated in stack,\nand will automatically be destroyed when the main returns:" << std::endl;
	z1.announce();
	std::cout << std::endl;
	std::cout << "________________________________________" << std::endl;
	std::cout << "Following zombies are also created, allocated in stack,\nand will automatically be destroyed when the function returns:" << std::endl;
	randomChump("Shaun");
	randomChump("Ed");
	std::cout << "________________________________________" << std::endl;
	std::cout << "A zombie is created, allocated in heap,\nand needs be destroyed by calling delete:" << std::endl;
	z2->announce();
	std::cout << "________________________________________" << std::endl;
	std::cout << "Calling delete to free David." << std::endl;
	delete z2;
	std::cout << "________________________________________" << std::endl;
	std::cout << "Main returns and Barbara is automatically destroyed:" << std::endl;
	return 0;
}

// Stack: Objects created directly in a function (without new) are allocated on the stack.
// 	They are automatically destroyed when they go out of scope (i.e., when the function returns).
// 	ie. Zombie	z1("Barbara");
// Heap: Objects created using the new operator are allocated on the heap.
// 	They persist until explicitly deleted with delete.
// 	ie. Zombie	*z2 = newZombie("David"): return (new Zombie(name));