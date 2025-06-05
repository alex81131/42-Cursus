#include "ATarget.hpp"

ATarget::ATarget(const std::string& type): _type(type) {}

ATarget::ATarget(const ATarget& other)
{*this = other;}

ATarget&	ATarget::operator=(const ATarget& other)
{
	(void) other;
	return *this;
}

ATarget::~ATarget() {}

const std::string&	ATarget::getType() const
{return _type;}

void	ATarget::getHitBySpell(const ASpell& spell) const
{std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;}