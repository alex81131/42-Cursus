#pragma once
# include "ASpell.hpp"

class	Fwoosh: public ASpell
{
	public:
	Fwoosh();
	~Fwoosh();
	ASpell*	clone() const;

	private:
		Fwoosh(const Fwoosh& other);
		Fwoosh&	operator = (const Fwoosh& other);
};