#include "sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4 || !std::string(av[2]).size()) {
		std::cerr << "Error: invalid arguments." << std::endl;
		return 1;
	}
	if (sed::replace(av[1], av[2], av[3])) {
		return 1;
	}
	return 0;
}