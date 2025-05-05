#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title): name(name), title(title)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::map<std::string, ASpell*>::iterator	it;

	for (it = spells.begin(); it != spells.end(); ++it)
		delete it->second;
	spells.clear();
	std::cout << this->name << ": My job here is done!" << std::endl;
}
const std::string&	Warlock::getName() const {
	return this->name;
}
const std::string&	Warlock::getTitle() const {
	return this->title;
}
void	Warlock::setTitle(const std::string& title) {
	this->title = title;
}
void	Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spell)
{
	if (spell)
		spells[spell->getName()] = spell->clone();
}

void	Warlock::forgetSpell(const std::string spellName)
{
	std::map<std::string, ASpell*>::iterator	it = spells.find(spellName);

	if (it != spells.end())
	{
		delete it->second;
		spells.erase(it);
	}
}
// std::map stores key-value pairs:
// 	first: The key of the pair, ie. the name of the spell.
// 	second: The value associated with that key, ie. ASPell*

void	Warlock::launchSpell(const std::string spellName, const ATarget& target)
{
	std::map<std::string, ASpell*>::iterator	it = spells.find(spellName);

	if (it != spells.end())
		it->second->launch(target);
}