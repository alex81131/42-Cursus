#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <sstream>
# include "Contact.hpp"

class	PhoneBook {

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add_contact(void);
		void	search(void) const;
		void	print(void) const;

	private:
		int		_index;
		Contact	_contact[8];

};

#endif
// Contact	_contact[8]:
// 	an array of Contact objects

// <iostream>:
// 	std::cout, std::cin
// <sstream>:
// 	std::stringstream
// <iomanip>:
// 	std::setw