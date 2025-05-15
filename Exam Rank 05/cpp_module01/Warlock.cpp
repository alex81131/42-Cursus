#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title): _name(name), _title(title)
{std::cout << this->_name << ": This looks like another boring day." << std::endl;}

Warlock::~Warlock()
{
	std::map<std::string, ASpell*>::iterator	it;

	for (it = _spells.begin(); it != _spells.end(); ++it)
		delete it->second;
	_spells.clear();
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

const std::string&	Warlock::getName() const
{return this->_name;}

const std::string&	Warlock::getTitle() const
{return this->_title;}

void	Warlock::setTitle(const std::string& title)
{this->_title = title;}

void	Warlock::introduce() const
{std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;}

void	Warlock::learnSpell(ASpell* spell)
{
	if (spell)
		_spells[spell->getName()] = spell->clone();
}

void	Warlock::forgetSpell(const std::string spellName)
{
	std::map<std::string, ASpell*>::iterator	it = _spells.find(spellName);

	if (it != _spells.end())
	{
		delete it->second;
		_spells.erase(it);
	}
}
// std::map stores key-value pairs:
// 	first: The key of the pair, ie. the name of the spell.
// 	second: The value associated with that key, ie. ASpell*

void	Warlock::launchSpell(const std::string spellName, const ATarget& target)
{
	std::map<std::string, ASpell*>::iterator	it = _spells.find(spellName);

	if (it != _spells.end())
		it->second->launch(target);
}