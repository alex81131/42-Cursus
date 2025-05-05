#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title): _name(name), _title(title), _spellBook(new SpellBook)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	delete _spellBook;
	std::cout << this->_name << ": My job here is done!" << std::endl;
}
const std::string&	Warlock::getName() const {
	return this->_name;
}
const std::string&	Warlock::getTitle() const {
	return this->_title;
}
void	Warlock::setTitle(const std::string& title) {
	this->_title = title;
}
void	Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spell)
{
	if (spell)
		_spellBook->learnSpell(spell);
}

void	Warlock::forgetSpell(const std::string spellName)
{
	_spellBook->forgetSpell(spellName);
}

void	Warlock::launchSpell(const std::string spellName, const ATarget& target)
{
	ASpell*	spell = _spellBook->createSpell(spellName);

	if (spell)
	{
		spell->launch(target);
		delete spell;
	}
}