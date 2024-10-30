#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Character: public ICharacter
{
	public:
		Character(void);								// Default constructor
		Character(std::string const& _name);			// Parameterized Constructor
		Character(const Character& src);				// Copy constructor
		Character&	operator = (const Character& src);	// Assignment operator
		~Character(void);								// Destructor

		std::string const&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

	private:
		AMateria*			_inventory[4];
		std::string			_name;
};


#endif