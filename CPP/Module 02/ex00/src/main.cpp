#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl	h;

	if (ac != 2 || !av[1])
	{
		std::cout << "Error: incorrect input." << std::endl;
		return 1;
	}
	h.complain(av[1]);
	return 0;
}