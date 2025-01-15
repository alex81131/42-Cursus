#include "MutantStack.hpp"
#include <list>
#include <algorithm>

int	main()
{
	MutantStack<int>	mstack;
	std::list<int>		lst;

	mstack.push(5);									// stack adds elements from the top
	lst.push_back(5);								// list adds elements from the end
	mstack.push(17);
	lst.push_back(17);
	std::cout << "____________ Mutant Stack ____________" << std::endl;
	std::cout << mstack.top() << std::endl;			// Retrieves the last value added
	mstack.pop();									// Removes the top value
	std::cout << mstack.size() << std::endl;		// Now only "5" remains.
	std::cout << "________________ List ________________" << std::endl;
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "_______ Mutant Stack Iteration _______" << std::endl;
	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "___________ List Iteration ___________" << std::endl;
	std::list<int>::iterator	itl = lst.begin();
	std::list<int>::iterator	itle = lst.end();
	while (itl != itle)
	{
		std::cout << *itl << std::endl;
		++itl;
	}
	std::stack<int>	s(mstack);
	return 0;
}