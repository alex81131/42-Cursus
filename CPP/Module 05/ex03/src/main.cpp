#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::cout << std::endl;
	std::cout << "__________________Shrubbery__________________" << std::endl;
	try
	{
		Bureaucrat				Eleonore("Eleonore", 13);
		Bureaucrat				Anne("Anne", 150);
		ShrubberyCreationForm	f1("Eleonore");
		ShrubberyCreationForm	f2("Anne");

		std::cout << "---------------------------------------------" << std::endl;
		std::cout << Eleonore;
		std::cout << Anne << std::endl;
		Eleonore.signForm(f1);
		Anne.signForm(f2);
		std::cout << "---------------------------------------------" << std::endl;
		Eleonore.executeForm(f1);
		Anne.executeForm(f2);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	std::cout << std::endl;
		std::cout << "_____________________________________________" << std::endl;
	try
	{
		Bureaucrat				Eleonore("Eleonore", 13);
		Bureaucrat				Anne("Anne", 150);
		ShrubberyCreationForm	f1("Eleonore");
		ShrubberyCreationForm	f2("Anne");

		std::cout << "---------------------------------------------" << std::endl;
		std::cout << Eleonore;
		std::cout << Anne << std::endl;
		Eleonore.signForm(f1);
		Eleonore.executeForm(f1);
		Anne.executeForm(f2);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "___________________Robotomy___________________" << std::endl;
	try
	{
		Bureaucrat			Anne("Anne", 60);
		Bureaucrat			Lorreta("Lorreta", 11);
		RobotomyRequestForm	f1("Anne");
		RobotomyRequestForm	f2("Lorreta");

		std::cout << "----------------------------------------------" << std::endl;
		std::cout << Anne;
		std::cout << Lorreta << std::endl;
		Anne.signForm(f1);
		Lorreta.signForm(f2);
		std::cout << "----------------------------------------------" << std::endl;
		Anne.executeForm(f1);
		Lorreta.executeForm(f2);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "_____________Presidential Pardon______________" << std::endl;
	try
	{
		Bureaucrat				Eleonore("Eleonore", 1);
		Bureaucrat				Anne("Anne", 23);
		PresidentialPardonForm	f1("Eleonore");
		PresidentialPardonForm	f2("Anne");

		std::cout << "----------------------------------------------" << std::endl;
		std::cout << Eleonore;
		std::cout << Anne << std::endl;
		Eleonore.signForm(f1);
		Anne.signForm(f2);
		std::cout << "----------------------------------------------" << std::endl;
		Eleonore.executeForm(f1);
		Anne.executeForm(f2);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
}

// In Shrubbery, there's one different exception at the end:
// 	[Exception] Grade too low.
// 	because it's checked while signing.
// 	The others threw the exceptions in the execution's signature check.
// 	Hence the sole different behavior.