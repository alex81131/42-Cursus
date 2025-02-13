#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "[Error] Usage: " << av[0] << " <RPN>" << std::endl;
		return 1;
	}
	try
	{
		RPN	r;

		std::cout  << r.calculation(av[1]) << std::endl;
	}
	catch(const std::logic_error& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
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