#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal*	meta = new Animal();
	const Animal*	i = new Cat();
	const Animal*	j = new Dog();

	std::cout << "_____________________________________" << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "____________Wrong animals____________" << std::endl;

	const WrongAnimal*	k = new WrongAnimal();
	const WrongCat*		l = new WrongCat();
	std::cout << "_____________________________________" << std::endl;
	std::cout << k->getType() << std::endl;
	k->makeSound();
	std::cout << l->getType() << std::endl;
	l->makeSound();

	std::cout << "_____________________________________" << std::endl;
	delete meta;
	delete i;
	delete j;
	delete k;
	delete l;
	return 0;
}
