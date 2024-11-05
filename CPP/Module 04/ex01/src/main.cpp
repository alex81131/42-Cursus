#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal*	array[100];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			array[i] = new Dog();
			std::cout << "Animal[" << i << "] created." << std::endl;
		}
		else
		{
			array[i] = new Cat();
			std::cout << "Animal[" << i << "] created." << std::endl;
		}
	}
	std::cout << "__________Deep copy check____________" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		array[i]->makeSound();
		if (Cat* cat = dynamic_cast<Cat*>(array[i]))
			cat->showIdeas();
		else if (Dog* dog = dynamic_cast<Dog*>(array[i]))
			dog->showIdeas();
		std::cout << std::endl;
	}
	std::cout << "_____________________________________" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		delete array[i];
		std::cout << "Animal[" << i << "] deleted." << std::endl;
	}
	return 0;
}

// dynamic_cast:
// 	checks if the element can be cast to a Cat*, returning success only if so.