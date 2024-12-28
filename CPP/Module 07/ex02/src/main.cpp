#include "iter.hpp"

int	main() {
	std::cout << "_____________ Int test _____________" << std::endl;
	int		int_arr[5] = {1, 2, 3, 4, 5};
	iter<int>(int_arr, 5, print_one<int>);
	std::cout<< std::endl << "Triple:" << std::endl;
	iter<int>(int_arr, 5, triple<int>);
	iter<int>(int_arr, 5, print_one<int>);
	std::cout << std::endl << "Next:" << std::endl;
	iter<int>(int_arr, 5, print_next<int>);

	std::cout << "__________ const int test __________" << std::endl;
	int	const	int_arr_c[5] = {12, 11, 6378, 2, 299792458};
	iter<int>(int_arr_c, 5, print_one_const<int>);

	std::cout << "____________ Float test ____________" << std::endl;
	float	float_arr[6] = {0.11, 2.21, 3.03, 11.11, -2.04, -1.23};
	iter<float>(float_arr, 6, print_one<float>);
	std::cout<< std::endl << "Triple:" << std::endl;
	iter<float>(float_arr, 6, triple<float>);
	iter<float>(float_arr, 6, print_one<float>);

	std::cout << "____________ Char test _____________" << std::endl;
	char	char_arr[3] = {'!', '&', '#'};
	iter<char>(char_arr, 3, print_one<char>);
	std::cout<< std::endl << "Triple:" << std::endl;
	iter<char>(char_arr, 3, triple<char>);
	iter<char>(char_arr, 3, print_one<char>);
	
	std::cout << "___________ String test ____________" << std::endl;
	std::string		str[2] = {"Eleonore", "is having so much fun in Vienna."};
	iter<std::string>(str, 2, print_one<std::string>);
	
	std::cout << "________ const string test _________" << std::endl;
	std::string	const	str_c[2] = {"Anne", "is lost in Taiwan."};
	iter<std::string>(str_c, 2, print_one_const<std::string>);
	return 0;
}