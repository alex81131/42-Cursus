#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB {

	public:
		HumanB(const std::string& name);
		~HumanB(void);

		void		attack(void);
		void		setWeapon(Weapon& weapon);

	private:
		std::string	_name;
		Weapon*		_weapon;

};

#endif

// The pointer (Weapon*) indicates that HumanB can choose to own the Weapon object, potentially allowing it to manage its memory. This means HumanB could create or delete the weapon object.

// Can't define set_Weapon(Weapon& weapon) as set_Weapon(const Weapon& weapon)
// 	cuz in HumanB.cpp, you wouldn't be able to this->_weapon = &weapon;