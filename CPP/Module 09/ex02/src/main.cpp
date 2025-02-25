#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: Insufficienty input." << std::endl;
		return 1;
	}

	std::vector<int>	value;
	for (int i = 1; i < ac; i++)
	{
		if (!PmergeMe::isPositiveNum(av[i]))
		{
			std::cerr << "Error: Only accept natural numbers (positive integers)." << std::endl;
			return 1;
		}
		value.push_back(std::atoi(av[i]));
	}
	PmergeMe	sorter(value);
	sorter.sort();
	return 0;
}
// 1. Simple:
// 	3 4 +
// 		7
// 2. Multiply:
// 	2 3 + 5 *
// 		25
// 3. All:
// 	9 3 / 2 + 4 *
// 		20
// 4. Priorities:
// 	3 4 + 5 6 + *
// 		77
// 5. Any number:
// 	99 11 / -2 + 4 *
// 		28