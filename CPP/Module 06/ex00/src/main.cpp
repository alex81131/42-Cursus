#include "Intern.hpp"

int	main()
{
	std::cout << std::endl;
	std::cout << "__________________Intern__________________" << std::endl;
	Intern	Eleonore;
	AForm	*rrf;
	AForm	*ppf;

	std::cout << "---------------------------------------------" << std::endl;
	rrf = Eleonore.makeForm("robotomy request", "Aliance Francaise");
	std::cout << std::endl;
	ppf = Eleonore.makeForm("presidential pardon", "Yuki");
	std::cout << std::endl;
	Eleonore.makeForm("Inexistent", "Raphael");
	std::cout << "---------------------------------------------" << std::endl;
	delete rrf;
	delete ppf;
	return 0;
}
