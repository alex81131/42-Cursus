#include "Harl.hpp"

int main()
{
	std::string	lv;
	Harl		h;

	std::cout << "Enter a level: ";
	std::cin >> lv;
	std::cout << "________________________________________" << std::endl;
	h.complain(lv);
	return 0;
}