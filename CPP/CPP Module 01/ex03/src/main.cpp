#include <iostream>
#include <string>

int	main() {
	std::string		stringVAR = "HI THIS IS BRAIN";
	std::string*	stringPTR = &stringVAR;
	std::string&	stringREF = stringVAR;

	std::cout << "Address of stringVAR     :" << &stringVAR << std::endl;
	std::cout << "Address held by stringPTR:" << stringPTR << std::endl;
	std::cout << "Address held by stringREF:" << &stringREF <<std::endl;
	std::cout << "________________________________________" << std::endl;
	std::cout << "Value of stringVAR           :" << stringVAR << std::endl;
	std::cout << "Value pointed to by stringPTR:" << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF:" << stringREF << std::endl;
	return 0;
}

// C++ has a slight different convention as where the * and & are placed during declaration.