#include "Bureaucrat.hpp"

int	main()
{
	std::cout << std::endl << "____________Increment error____________" << std::endl;
	try
	{
		Bureaucrat	Lorreta("Lorreta", 2);

		std::cout << Lorreta << std::endl;
		Lorreta.increment();
		std::cout << Lorreta << std::endl;
		Lorreta.decrement();
		std::cout << Lorreta << std::endl;
		Lorreta.increment();
		Lorreta.increment();
		std::cout << Lorreta << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Increment error: " << e.what() << '\n';
	}
	std::cout << std::endl << "____________Decrement error____________" << std::endl;
	try
	{
		Bureaucrat	Anne("Anne", 150);

		std::cout << Anne << std::endl;
		Anne.decrement();
		std::cout << Anne << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Decrement error: " << e.what() << '\n';
	}
	std::cout << std::endl << "__________Invalid grade error__________" << std::endl;
	try
	{
		Bureaucrat	Eleonore("Eleonore", -1);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Invalid grade: " << e.what() << '\n';
	}
	std::cout << std::endl;
}