#pragma once
# include <string>
# include <map>
# include "ASpell.hpp"

class	SpellBook
{
	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell* spell);
		void	forgetSpell(const std::string& spellName);
		ASpell*	createSpell(const std::string& spellName);

	private:
		std::map<std::string, ASpell*>	_spells;

		SpellBook(const SpellBook& other);					// SpellBook bob(jim);
		SpellBook&	operator = (const SpellBook& other);	// bob = jim;
};