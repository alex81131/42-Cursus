#include "HumanB.hpp"

HumanB::HumanB(const std::string& name): _name(name) {
	this->_weapon = NULL;
}

HumanB::~HumanB(){}

void	HumanB::attack(void) {
	if (!this->_weapon)
		std::cout << this->_name << " attacks with bare hands" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
	std::cout << this->_name << " picks up the weapon \"" << this->_weapon->getType() << "\"" << std::endl;
}