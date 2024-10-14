#include "phonebook.hpp"

int	main() {

	std::string	input;
	PhoneBook	phonebook;

	std::cout << "Welcome to my phonebook." << std::endl;
	while (!std::cin.eof()) {
		std::cout << "Enter a command: ";
		if (!std::getline(std::cin, input)) {
			std::cout << std::endl;
			break ;
		}
		if (input == "EXIT")
			break ;
		if (input == "ADD")
			phonebook.add_contact();
		if (input == "SEARCH") {
			phonebook.print();
			phonebook.search();
		}
	}
	if (std::cin.eof())
		std::cout << "EoF detected. Exiting program." << std::endl;
	else
		std::cout << "Exiting program." << std::endl;
	return 0;
}