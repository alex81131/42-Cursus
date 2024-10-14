#include "phonebook.hpp"

PhoneBook::PhoneBook() {

	// std::cout << "Phonebook constructed." << std::endl;
	this->_index = 0;
}

PhoneBook::~PhoneBook() {

	// std::cout << "Phonebook destroyed." << std::endl;
}

void	PhoneBook::add_contact(void) {

	int			i = this->_index % 8;
	std::string	str = "";

	if (this->_index > 7)
		std::cout << "Warning: Over maximum capacity of 8 contacts. Overwritting oldest data." << std::endl;
	while (!std::cin.eof() && str == "") {
		std::cout << "Enter first name:";
		if (std::getline(std::cin, str) && str != "")
			this->_contact[i].set_fname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "") {
		std::cout << "Enter last name:";
		if (std::getline(std::cin, str) && str != "")
			this->_contact[i].set_lname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "") {
		std::cout << "Enter nick name:";
		if (std::getline(std::cin, str) && str != "")
			this->_contact[i].set_nick(str);
	}
	str = "";
	while (!std::cin.eof() && str == "") {
		std::cout << "Enter phone number:";
		if (std::getline(std::cin, str) && str != "")
			this->_contact[i].set_number(str);
	}
	str = "";
	while (!std::cin.eof() && str == "") {
		std::cout << "Enter darkest secret:";
		if (std::getline(std::cin, str) && str != "")
			this->_contact[i].set_secret(str);
	}
	if (std::cin.eof())
		std::cout << std::endl << "Exit ADD due to EoF." << std::endl;
	else
		std::cout << "Contact " << i + 1 << " is added successfully." << std::endl;
	this->_index++;
}

void	PhoneBook::search(void) const {

	std::string	input;
	int			i;

	// identify valid index input
	while (true) {

		std::cout << "Enter the index of a contact: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << std::endl << "Exit SEARCH due to EoF." << std::endl;
			return ;
		}
		std::stringstream ss(input);
		if (ss >> i && ss.eof() && (0 < i && i < 9))
			break ;
		std::cout << "Invalid index. Try again." << std::endl;
	}
	// print searched contact
	std::cout << "First name    : " << _contact[i - 1].get_fname() << std::endl;
	std::cout << "Last name     : " << _contact[i - 1].get_lname() << std::endl;
	std::cout << "Nick name     : " << _contact[i - 1].get_nick() << std::endl;
	std::cout << "Phone number  : " << _contact[i - 1].get_number() << std::endl;
	std::cout << "Darkest secret: " << _contact[i - 1].get_secret() << std::endl;
}

static	std::string	cut_size(std::string str, unsigned int max) {

	if (str.length() > max) {
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

void	PhoneBook::print(void) const {

	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	for (int i = 0; i < this->_index && i < 8; i++) {
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << cut_size(this->_contact[i].get_fname(), 10);
		std::cout << "|" << std::setw(10) << cut_size(this->_contact[i].get_lname(), 10);
		std::cout << "|" << std::setw(10) << cut_size(this->_contact[i].get_nick(), 10);
		std::cout << "|" << std::endl;
	}
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}
// std::setw(n): printf the following output with a total width of n characters,
// right-aligned

// std::stringstream ss(input);
// if (ss >> i && (0 < i && i < 9) && ss.eof())
// 	take the input string and transform it into int i (if possible),
// 	simultaneously checking if it's a number, and there's nothing left.

// std::stringstream is a string management tool that can parse input
// and convert it into other types.