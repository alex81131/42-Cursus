#include "Span.hpp"

int	main()
{
	std::cout << "_________ Default Test sp1 _________" << std::endl;
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{sp.addNumber(6);}
	catch(const std::exception& e)
	{std::cerr << e.what() << std::endl;}

	std::cout << std::endl << "_________ sp2 Tests _________" << std::endl;
	Span	sp2 = Span(10);

	try
	{sp2.longestSpan();}
	catch(const std::exception& e)
	{std::cerr << e.what() << std::endl;}
	try
	{sp2.shortestSpan();}
	catch(const std::exception& e)
	{std::cerr << e.what() << std::endl;}
	sp2.addNumber(2);
	try
	{sp2.longestSpan();}
	catch(const std::exception& e)
	{std::cerr << e.what() << std::endl;}

	std::cout << std::endl << "_________ sp3 Tests _________" << std::endl;
	Span	sp3 = Span(10000);

	sp3.storeNumbers(10000);
	std::cout <<"Numbers added." << std::endl;
	// sp3.printAll();
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;
	return 0;
}