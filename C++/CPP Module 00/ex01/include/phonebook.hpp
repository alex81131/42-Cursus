#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

// # include <iomanip>
// # include <sstream>
# include "contact.hpp"

class	PhoneBook {

	private:
		int		_index;
		Contact	_contact[8];

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void);
		void	print(void);
};

#endif
// Contact	_contact[8]:
// 	an array of Contact objects

// <iostream>:
// 	std::cout, std::cin
// <sstream>:
// 	std::istringstream