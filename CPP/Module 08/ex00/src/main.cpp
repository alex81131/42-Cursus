#include "easyfind.hpp"
#include <list>
#include <vector>

int	main(void)
{
	std::cout << "_________ int list test _________" << std::endl;
	std::list<int>	int_list;					// implements a doubly-linked list

	int_list.push_back(37);						// Unlike a singly-linked list, where you can only traverse forward,
	int_list.push_back(99);						// a doubly-linked list allows both forward and backward traversal
	int_list.push_back(0);
	int_list.push_back(12);						// push_back adds the element to the end of the list,
	int_list.push_back(-3);						// ie. now we have a list with the elements:
	int_list.push_back(12);						// 	37, 99, 0, 12, -3, 12.

	try
	{
		std::list<int>::iterator	found_list = ::easyfind(int_list, 12);

		std::cout << "First found(12): " << *found_list << std::endl;
		std::cout << "Next item(-3): " << *(++found_list) << std::endl;
		::easyfind(int_list, 77);
	}

// ::easyfind:
// 	The :: before easyfind is used to specify that you want to call the easyfind function from the global namespace.
// 	The :: ensures the compiler looks for easyfind in the global scope, rather than a possible local scope or class member with the same name.

	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "_________ int vector test _________" << std::endl;
	std::vector <int>	int_vector;				// implements a dynamic array.

	int_vector.push_back(11);					// Provides contiguous memory storage, allowing fast random access by index
	int_vector.push_back(22);					// (just another linked list)
	int_vector.push_back(33);
	int_vector.push_back(22);
	int_vector.push_back(11);

	try
	{
		std::vector<int>::iterator	found_vector = ::easyfind(int_vector, 22);

		std::cout << "First found(22): " << *found_vector << std::endl;
		std::cout << "Next item(33): " << *(++found_vector) << std::endl;
		::easyfind(int_list, 77);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

// std::list:
// 	1. Implements a doubly-linked list.
// 	2. Each element has pointers to the next and previous elements, allowing efficient insertions and deletions anywhere in the list.
// 	3. Accessing elements is less efficient because it requires traversal.

// std::vector:
// 	1. Implements a dynamic array.
// 	2. Provides contiguous memory storage, allowing fast random access by index.
// 	3. Adding or removing elements at the end is efficient, but modifying elsewhere can be costly due to shifting.