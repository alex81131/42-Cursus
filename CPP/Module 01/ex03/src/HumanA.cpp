#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, const Weapon& weapon):
	_name(name),
	_weapon(weapon) {

	std::cout << "\"" << this->_name << "\" is created with the weapon \"" << weapon.getType() << "\"" << std::endl;
}

HumanA::~HumanA(){}

void	HumanA::attack(void){

	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

// const Weapon& weapon is a class reference of the type "const Weapon"
// 	so in order to print the name of the weapon, you need to use ".getType()"