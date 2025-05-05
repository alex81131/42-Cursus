#pragma once
# include <string>
# include <iostream>
# include <map>
# include "ASpell.hpp"
# include "SpellBook.hpp"

class	Warlock
{
	public:
		Warlock(const std::string& name, const std::string& title);
		~Warlock();

		const std::string&	getName() const;
		const std::string&	getTitle() const;
		void				setTitle(const std::string& title);

		void				introduce() const;
		void				learnSpell(ASpell* spell);
		void				forgetSpell(const std::string spellName);
		void				launchSpell(const std::string spellName, const ATarget& target);

	private:
		std::string	_name;
		std::string	_title;
		SpellBook*	_spellBook;

		Warlock();		// Private default constructor to prevent instantiation without name and title
		Warlock(const Warlock& other);					// Warlock bob(jim);
		Warlock&	operator = (const Warlock& other);	// bob = jim;
};