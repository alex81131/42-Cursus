#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource*	src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "_____________________________________" << std::endl;
	ICharacter*		me = new Character("me");

	AMateria*	tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "_____________________________________" << std::endl;
	ICharacter*		bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl << "-------Materia inventory test--------" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	AMateria*	tmp_mat = new Ice();

	src->learnMateria(tmp_mat);
	delete tmp_mat;

	std::cout << std::endl << "----------Materia equip test---------" << std::endl;
	bob->equip(tmp);
	tmp = src->createMateria("N/A");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->equip(tmp);

	std::cout << std::endl << "---------Materia unequip test--------" << std::endl;
	me->unequip(1);
	me->use(1, *bob);
	me->unequip(1);

	std::cout << "_____________________________________" << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}

// Memory leaks:
// 1. in MateriaSource:
// 	src->learnMateria(new Ice()); fails on the 5th element to learn.
// 	Need to delete the "new Ice()" above.
// 2. Materias on the characters:
// 	the materias unequipped won't be able to be cleaned by deleting the character.