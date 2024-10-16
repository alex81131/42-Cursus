#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA {

	public:
		HumanA(const std::string& name, const Weapon& weapon);
		~HumanA(void);

		void			attack(void);

	private:
		std::string		_name;
		const Weapon&	_weapon;

};

#endif

// Use referernce: const std::string&, to avoid duplication and hence more efficient.

// The reference (const Weapon&) indicates that HumanA does not own the Weapon object; it merely refers to an existing Weapon object. This means that HumanA expects the Weapon to outlive it, and it won't manage the memory of the Weapon.
// Since it’s a reference, HumanA is bound to a specific Weapon for its entire lifetime.