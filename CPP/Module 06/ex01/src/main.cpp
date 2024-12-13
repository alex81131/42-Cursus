#include "Serializer.hpp"

int	main(void)
{
	Data	*p1 = new Data();
	Data	*p2 = new Data('@', 11, 5.18, "Eleonore", p1);

	uintptr_t	raw1 = Serializer::serialize(p1);
	uintptr_t	raw2 = Serializer::serialize(p2);

	std::cout << std::endl;
	std::cout << "______________Serialization Completed______________" << std::endl;
	std::cout << "raw1: " << raw1 << std::endl;
	std::cout << "raw2: " << raw2 << std::endl;

	Data*	d_raw1 = Serializer::deserialize(raw1);
	Data*	d_raw2 = Serializer::deserialize(raw2);

	std::cout << std::endl;
	std::cout << "_____________Deserialization Completed_____________" << std::endl;
	p1->printData();
	std::cout << "           [Before↑    Data 1    After↓]           " << std::endl;
	d_raw1->printData();
	std::cout << std::endl;
	std::cout << "___________________________________________________" << std::endl;
	p2->printData();
	std::cout << "           [Before↑    Data 2    After↓]           " << std::endl;
	d_raw2->printData();
	delete p1;
	delete p2;
	return 0;
}