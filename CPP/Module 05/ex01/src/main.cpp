#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "\n______________Sign Forms_______________" << std::endl;
	try
	{
		Bureaucrat	Lorreta("Lorreta", 11);
		std::cout << Lorreta << std::endl;

		Form		f1("form1", 12, 20);
		std::cout << f1 << std::endl;
		Form		f2("form2", 2, 20);
		std::cout << f2 << std::endl;

		std::cout << "[Lorreta] Signing form1." << std::endl;
		Lorreta.signForm(f1);
		std::cout << f1 << std::endl;

		std::cout << "[Lorreta] Signing form2." << std::endl;
		Lorreta.signForm(f2);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Sign error: " << e.what() << '\n';
	}

	std::cout << "\n----------     Lorreta+     -----------" << std::endl;
	try
	{
		Bureaucrat	Lorreta("Lorreta", 11);
		Form		f2("form2", 2, 20);

		Lorreta.increment();
		Lorreta.increment();
		Lorreta.increment();
		std::cout << "[Lorreta] Signing form2." << std::endl;
		Lorreta.signForm(f2);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Sign error: " << e.what() << '\n';
	}

	std::cout << "\n______________Form error_______________" << std::endl;
	try
	{
		Bureaucrat	Anne("Anne", 150);
		Form		f3("form3", 0, 150);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Form error: " << e.what() << '\n';
	}

	std::cout << "\n____________Decrement error____________" << std::endl;
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
	std::cout << "\n__________Invalid grade error__________" << std::endl;
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