#include <iostream>
#include <Array.hpp>
#include <cstdlib>	// rand and srand
#include <string>	// string test

#define MAX_VAL 750
int main(int, char**)
{
/* * * * * * * * test from the subject * * * * * * * */
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;

/* * * * * * * * more tests * * * * * * * */
	std::cout << std::endl << "______________More Tests______________" << std::endl;
	Array<std::string>	message(11);
	// Create index-based messages
	for (int i = 0; i < 11; i++)
	{
		message[i] = "This is message_";
		std::stringstream	ss;
		ss << i;
		message[i].append(ss.str());
	}
	std::cout << "Array size: " << message.size() << std::endl;
	std::cout << "Array content:" << std::endl << message << std::endl;

	std::cout << "_______Copy and Memory Check__________" << std::endl;
	Array<std::string>	arr(2);
	arr[0] = "Eleonore";
	arr[1] = "Anne";
	std::cout << "Array size: " << arr.size() << std::endl;
	std::cout << "Array content: " << std::endl << arr << std::endl;
	std::cout << "* * * ↑Before  ↓After Copy Assignment * * *" << std::endl;
	arr = message;
	std::cout << "Array size: " << arr.size() << std::endl;
	std::cout << "Array content:" << std::endl << arr << std::endl;
	return 0;
}