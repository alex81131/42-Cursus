#pragma once
# include <string>
# include <iostream>
# include "ATarget.hpp"

class	ATarget;

class	ASpell
{
	public:
		ASpell();
		ASpell(const std::string& name, const std::string& effects);
		ASpell(const ASpell& other);
		ASpell&	operator=(const ASpell& other);
		virtual	~ASpell();

		const std::string&	getName() const;
		const std::string&	getEffects() const;
		virtual ASpell*		clone() const = 0;
		void				launch(const ATarget& target) const;

	protected:
		std::string	_name;
		std::string	_effects;
};