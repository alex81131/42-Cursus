#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

int	main(void)
{
	Base	*obj = generate();

	std::cout << "Pointer check:" << std::endl;
	identify(obj);
	std::cout << std::endl;
	std::cout << "Reference check:" << std::endl;
	identify(*obj);
	delete(obj);
	return 0;
}