#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

// Use current time to generate a number randomly.
// <ctime>:
// 	time(0): current time
// <cstdlib>:
// 	srand(unsigned int): to initialize the pseudo-random number generator
// 	rand(void): randomly generate a number
Base	*generate(void)
{
	Base	*result;

	srand(static_cast<unsigned int>(time(0)));
	if (rand() % 3 == 0)
		result = new A;
	else if (rand() % 3 == 1)
		result = new B;
	else
		result = new C;
	return result;
}
// Although the generate() function returns a Base*,
// 	that pointer can indeed point to an object of type A, B, or C.
// This is because A, B, and C are derived from Base
// 	and are therefore compatible with Base* through inheritance.

// A object is of type A, but also compatible with type Base because of inheritance.
// dynamic_cast checks if the object is compatible with the target.
// 	So an A object can be cast into only A or Base type.
void	identify(Base *p)
{
	A	*ptr_A = dynamic_cast<A*>(p);
	B	*ptr_B = dynamic_cast<B*>(p);
	C	*ptr_C = dynamic_cast<C*>(p);

	if (ptr_A)
		ptr_A->id();
	if (ptr_B)
		ptr_B->id();
	if (ptr_C)
		ptr_C->id();
}
// When using dynamic_cast with pointers (Base*):
// 	- dynamic_cast returns a pointer to the casted type if the cast succeeds.
// 	- If the cast fails, it returns NULL.

// When using dynamic_cast with references (Base&):
// 	- dynamic_cast throws a std::bad_cast exception if the cast fails.
// 	- If the cast succeeds, it returns a reference to the casted type.
void	identify(Base &p)
{
	try
	{
		A	&ref_A = dynamic_cast<A&>(p);
		ref_A.id();
	}
	catch(const std::exception &e) {}
	try
	{
		B	&ref_B = dynamic_cast<B&>(p);
		ref_B.id();
	}
	catch(const std::exception &e) {}
	try
	{
		C	&ref_C = dynamic_cast<C&>(p);
		ref_C.id();
	}
	catch(const std::exception &e) {}
}
