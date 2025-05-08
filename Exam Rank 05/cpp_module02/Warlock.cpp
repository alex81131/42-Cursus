#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title): _name(name), _title(title), _spellbook(new SpellBook) {
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	delete _spellbook;
	std::cout << _name << ": My job here is done!" << std::endl;
}
const std::string&	Warlock::getName() const {
	return _name;
}
const std::string&	Warlock::getTitle() const {
	return _title;
}
void	Warlock::setTitle(const std::string& title) {
	_title = title;
}
void	Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spell)
{
	if (spell)
		_spellbook->learnSpell(spell);
}

void	Warlock::forgetSpell(const std::string spellName)
{
	_spellbook->forgetSpell(spellName);
}

void	Warlock::launchSpell(const std::string spellName, const ATarget& target)
{
	ASpell*	spell = _spellbook->createSpell(spellName);

	if (spell)
	{
		spell->launch(target);
		delete spell;
	}
}