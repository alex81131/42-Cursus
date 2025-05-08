#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell*>::iterator	it = _spells.begin(); it != _spells.end(); ++it)
		delete it->second;
	_spells.clear();
}

void	SpellBook::learnSpell(ASpell* spell)
{
	// Ignore duplicates
	if (spell && _spells.find(spell->getName()) == _spells.end())
		_spells[spell->getName()] = spell->clone();
}

void	SpellBook::forgetSpell(const std::string& spellName)
{
	std::map<std::string, ASpell*>::iterator	it = _spells.find(spellName);

	if (it != _spells.end())
	{
		delete it->second;
		_spells.erase(it);
	}
}

// Need to learn the spell so as to create it.
ASpell*	SpellBook::createSpell(const std::string& spellName)
{
	std::map<std::string, ASpell*>::iterator	it = _spells.find(spellName);

	if (it != _spells.end())
		return it->second->clone();
	return NULL;
}