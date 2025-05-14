#pragma once

# include "Data.hpp"
# include <iostream>
# include <string>
# include <stdint.h>


class	Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:	// Must not be instanciable by users
		Serializer(void);								// Default constructor
		Serializer(const Serializer& src);				// Copy constructor
		Serializer&	operator=(const Serializer& src);	// Assignment operator
		~Serializer(void);								// Destructor
};

// uintptr_t in <stdint.h>:
// 	designed to store pointers in a unsigned integer value