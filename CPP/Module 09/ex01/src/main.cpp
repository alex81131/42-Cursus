#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	BitcoinExchange	b;

	if (ac != 2)
	{
		std::cerr << "[Error] Usage: " << av[0] << " <input file>" << std::endl;
		return 1;
	}
	b.readDatabase();
	b.readInput(av[1]);
	return 0;
}