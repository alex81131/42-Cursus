#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: Insufficient input." << std::endl;
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
// https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php

// 1. vector: Input dependant
// 	a. Structure: One contiguous block of elements (e.g., [1, 2, 3, 4] at consecutive addresses).
// 	b. Fast when: Cache locality shines with a good input; fewer reallocations or shifts amplify this.
// 2. deque: Overall balanced
// 	a. Structure: A dynamic array of pointers (the "spine") where each pointer points to a block of elements
// 	(e.g., [ptr1, ptr2] where ptr1 → [1, 2] and ptr2 → [3, 4]).
// 	b. Efficient insert near ends helps with a tougher input, balancing block overhead.
// 3. list: Always slowest
// 	a. Structure: Scattered nodes linked by pointers.
// 	b. Cheap inserts, but traversal and cache misses kill performance.
// 	(cache miss: when the next node is not in the cache (integrated in the CPU),
// 				the PC has to withdraw it from the RAM (on the motherboard), which is much slower than caches)