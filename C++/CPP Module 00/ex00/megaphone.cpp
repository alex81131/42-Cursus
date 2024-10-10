#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < ac; i++)
	{
		std::string str(av[i]);
		for (size_t j = 0; j < str.length(); j++)
			std::cout << (char)std::toupper(str[j]);
	}
	std::cout << std::endl;
}
// 1. <iostream>
// 	for input and output operations
// 2. std::cout
// 	[std::]	prefix for the standard namespace
// 	cout:	character output
// 	(A namespace is a group of identifiers (functions, variables, classes, etc.))
// 3. The << operator:
// 	also known as the stream insertion operator, is used to send data to an output stream.
// - std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
// 	The first << operator sends the string literal into the std::cout stream.
// 	The second << operator takes the std::endl manipulator and inserts it into the same output stream, std::cout.
// 4. endl:
// 	Inserts a newline character and ensures that all output is displayed immediately.
// 5. std::string str(av[i]);
// 	Takes av[i] and converts the C-style string (a character array) to a C++ string object,
// 	naming it "str".