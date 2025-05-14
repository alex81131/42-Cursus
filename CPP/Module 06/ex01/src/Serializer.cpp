#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer& src) {(void) src;}

Serializer&	Serializer::operator=(const Serializer& src)
{
	(void) src;
	return *this;
}

Serializer::~Serializer(void) {}

// reinterpret_cast:
// 	allows low-level type conversion between:
// 	1. Pointer to Pointer (of a different type)
// 	2. Pointer to Integer, signed, unsigned and char...
// 	3. Integer to Pointer
uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	Data*	result = reinterpret_cast<Data*>(raw);

	return result;
}
